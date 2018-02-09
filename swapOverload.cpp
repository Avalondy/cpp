#include <iostream>
using namespace std;

inline void swap(double &i, double &j){
    double temp = i;
    i = j;
    j = temp;
}
inline void swap(int &i, int &j){
    int temp = i;
    i = j;
    j = temp;
}

int main(){
    int m=5, n=10;
    double x=5.3, y=10.6;
    cout << "Inputs: " << m << ", " << n <<endl;
    swap(m, n);
    cout << "Outputs: " << m << ", " << n <<endl;
    cout << "Double Inputs: " << x << ", " << y <<endl;
    swap(x, y);
    cout << "Double Outputs: " << x << ", " << y <<endl;
}
