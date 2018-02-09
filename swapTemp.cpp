#include <iostream>
#include <complex>
using namespace std;

template <class T>
inline void my_swap(T& d, T& s){
    T temp = d;
    d = s;
    s = temp;
}

int main(){
    int m=5, n=10;
    double x=5.3, y=10.6;
    complex<double> r(2.4, 3.5), s(3.4, 6.7);
    cout << "Inputs: " << m << ", " << n << endl;
    my_swap(m, n);
    cout << "Outputs: " << m << ", " << n << endl;
    cout << "Double Inputs: " << x << ", " << y << endl;
    my_swap(x, y);
    cout << "Double Outputs: " << x << ", " << y << endl;
    cout << "Complex Inputs: " << r << ", " << s << endl;
    my_swap(r, s);
    cout << "Complex Outputs: " << r << ", " << s << endl;
}
