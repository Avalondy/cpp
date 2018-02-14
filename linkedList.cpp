#include <iostream>
using namespace std;

struct slistelem{char data; slistelem* next;};

class slist{
    public:
        slist():h(0){}
        ~slist()
        prepend()
    private:
        slistelem* h;
};

void slist::prepend(char* c){
    slistelem* temp = new slistelem;
    temp -> next = h;
    temp -> data = c;
    h = temp;
}

slist::~slist(){
    cout << "destructor called" << endl;
    release();
}
