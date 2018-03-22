#include <iostream>
using namespace std;

template <class T>
class my_container{
    public:
        my_container(){a = new T[n];}
        ~my_container(){delete[] a;}
        explicit my_container(T* b): my_container(){
            for(int i=0; i<n; ++i) a[i] = b[i];
        }
        my_container(const my_container &b): my_container(){
            for(int i=0; i<n; ++i) a[i] = b.a[i];
        }
    private:
        T* a;
        int n;
};

int main(){
    my_container<int> a;
}
