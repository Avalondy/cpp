#include <iostream>
using namespace std;

template <class T>
class list_element{
    public:
        list_element(T n=0, list_element* ptr=nullptr):d(n), next(ptr){}
        T d;
        list_element* next;
};

template <class T>
class list{
    public:
        list():head(nullptr), cursor(nullptr){}
        void prepend(T n); //insert at front value n
        T get_element(){return cursor->d;}
        void advance(){cursor = cursor->next;}
        void print();
    private:
        list_element<T>* head;
        list_element<T>* cursor;
};

template <class T>
void list<T>::prepend(T n){
    if(head == 0)
        cursor = head = new list_element<T>(n, head);
    else
        head = new list_element<T>(n, head);
}

template <class T>
void list<T>::print(){
    list_element<T>* h = head;
    while(h != 0){
        cout << h->d << ", ";
        h = h->next;
    }
    cout << "###" << endl;
}

int main(){
    list<int> a, b;
    list<string> c;
    a.prepend(9); a.prepend(8);
    cout << "list a" << endl;
    a.print();
    for(int i=0; i<40; ++i)
        b.prepend(i*i);
    cout << "list b" << endl;
    b.print();
    c.prepend("abcd");
    cout << "list c" << endl;
    c.print();
    list<string> d = c;
    d.prepend("e");
    cout << "list d" << endl;
    d.print();
}
