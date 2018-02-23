#include <iostream>
#include <vector>
using namespace std;
int main(){
    int how_many;
    cout << "How many ints in data?: " << endl;
    cin >> how_many;
    vector<int> data(how_many);
    cout << "The contents of data:";
    for(auto it = data.begin(); it != data.end(); ++it)
        cin >> *it;
    cout << "Data contents:" << endl;
    for(auto it = data.begin(); it != data.end(); ++it)
        cout << *it << "\t";
    cout << endl;
}
