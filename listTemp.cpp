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
        list(const list&);
//        list(const T& a[], int);
        ~list();
        void prepend(T n); //insert at front value n
        T get_element(){return cursor->d;}
        void advance(){cursor = cursor->next;}
        void print();
    private:
        list_element<T>* head;
        list_element<T>* cursor;
};

template <class T>
list<T>::list(const list& lst){
    if(lst.head == nullptr){head = nullptr; cursor = nullptr;}
    else{
        cursor = lst.head;
        list_element<T>* h = new list_element<T>();
        list_element<T>* previous;
        head = h;
        h->d = lst.head->d;
        previous = h;
        for(cursor = cursor->next; cursor != nullptr; ){
            h = new list_element<T>();
            h->d = cursor->d;
            previous->next = h;
            cursor = cursor->next;
            previous = h;
        }
    cursor = head;
    }
}

/*template <class T>
list<T>::list(const T& a[], int n){
    list_element<T>* h = new list_element<T>();
    h->d = a[0];
    head = h;
    cursor = head;
    for(int i=1; i<n; ++i){
        h = new list_element<T>(n=a[i]);
        cursor->next = h;
       cursor = h;
    }
    cursor = head;
}*/

template <class T>
list<T>::~list(){
    for(cursor = head; cursor != 0; ){
        cursor = head->next;
        delete head;
        head = cursor;
    }
    cout << "Destructed!" << endl;
}

template <class T>
void list<T>::prepend(T n){
    if(head == nullptr)
        cursor = head = new list_element<T>(n, head);
    else
        head = new list_element<T>(n, head);
}

template <class T>
void list<T>::print(){
    list_element<T>* h = head;
    while(h != nullptr){
        cout << h->d << ", ";
        h = h->next;
    }
    cout << "###" << endl;
}

int main(){
    list<int> a, b;
    int data[10] = {3,4,6,7,-3,5};
//    list<int> d(data, 6);
//    list<int> e(data, 10);
    a.prepend(9); a.prepend(8);
    cout << "list a" << endl;
    a.print();
}
