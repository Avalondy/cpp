#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<int> data = {3,4,5,1,2};
    auto sum = 0;
    string str = "interesting!";
    for (auto d: data) sum += d;
    cout << "sum = " << sum << endl;
    cout << str << endl;
    for (auto &element: str) element += 1;
    cout << str << endl;
}
