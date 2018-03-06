#include <iostream>
#include <cassert>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

enum suit: short{SPADE, HEART, DIAMOND, CLUB};

class pips{
    public:
        pips(int val): v(val){assert(v>0 && v<14);}
        friend ostream& operator<<(ostream& out, const pips& p);
        int get_pips(){return v;}
    private:
        int v;
};

class card{
    public:
        card():s(suit::SPADE), v(1){}
        card(suit s, pips v):s(s),v(v){}
        friend ostream& operator<< (ostream&, const card&);
        suit get_suit(){return s;}
        pips get_pips(){return v;}
    private:
        suit s;
        pips v;
};

ostream& operator<<(ostream& out, const pips& p){
    out << p.v;
    return out;
}

ostream& operator<<(ostream& out, const suit& s){
    switch (s){
        case SPADE:     out << "Spade"; break;
        case HEART:     out << "Heart"; break;
        case DIAMOND:   out << "Diamond"; break;
        case CLUB:      out << "Club"; break;
    }
    return out;
}


ostream& operator<< (ostream& out, const card& c){
    out << c.v << c.s;
    return out;
}

void init_deck(vector<card>& d){
    for(int i=1; i<14; ++i){
        card c(suit::SPADE, i);
        d[i-1] = c;
    }
    for(int i=1; i<14; ++i){
        card c(suit::HEART, i);
        d[i+12] = c;
    }
    for(int i=1; i<14; ++i){
        card c(suit::DIAMOND, i);
        d[i+25] = c;
    }
    for(int i=1; i<14; ++i){
        card c(suit::CLUB, i);
        d[i+38] = c;
    }
}

void print(vector<card>& deck){
    for(auto cardval:deck)
        cout << cardval;
    cout << endl;
}

bool is_flush(vector<card>& hand){
    suit s = hand[0].get_suit();
    for(auto p=hand.begin()+1; p!=hand.end(); ++p)
        if(s != p->get_suit())
            return false;
    return true;
}

int main(){
    vector<card> deck(52);
    srand(time(0));
    init_deck(deck);
    long int how_many;
    int flush_count = 0;
    cout << "How many shuffles?  ";
    cin >> how_many;
    for(int loop=0; loop<how_many; ++loop){
        random_shuffle(deck.begin(), deck.end());
        vector<card> hand(5);
        int i=0;
        for(auto p=deck.begin(); i<5; ++p)
            hand[i++] = *p;
        if(is_flush(hand)) flush_count++;
    }
    cout << "Flushes " << flush_count << " out of " << how_many << endl;
    cout << "Expected flushes " << 4*13*12*11*10*9.0/(52*51*50*49*48) * how_many
        << " out of " << how_many << endl;
}
