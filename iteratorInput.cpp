#include <iostream>
#include <fstream>
#include <iterator>
#include <numeric>
using namespace std;

int main(){
    ifstream myin("data");
    istream_iterator<int> in(myin);
    istream_iterator<int> ino;
    cout << "Sum of data is " << accumulate(in, ino, 0) << endl;
}
