#include <iostream>
using namespace std;

template <class T>
T sum(const T data[], int size, T s=0){
    for(int i=0; i<size; ++i) s += data[i];
    return s;
}

int main(){
    cout << "Template for sum()" <<endl;
    int a[] = {1,2,3};
    double b[] = {2.1,2.2,2.3};
    char c[] = {'a', 'b', 'c'};
    cout << sum(a,3) << endl;
    cout << sum(b,3) << endl;
    cout << sum(c,3) << endl;
}
