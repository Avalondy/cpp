#include <iostream>
#include <numeric>
using namespace std;

int main(){
    double v1[3] = {1.0, 2.5, 4.6}, sum;
    sum = accumulate(v1, v1+3, 0.0, minus<int>());
    cout << "sum = " << sum << endl;
}
