#include <iostream>
using namespace std;

template <class T>
void my_print(const T data[], int size){
    for(int i=0;i<size;++i)
        cout << data[i] << '\t';
}

int main(){
    cout << "Template for my_print()" <<endl;
    int a[] = {1,2,3};
    double b[] = {2.1,2.2,2.3};
    my_print(a,3);
    cout << endl;
    my_print(b,3);
    cout << endl;
}
