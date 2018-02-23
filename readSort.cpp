#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ifstream word_file("/home/d/Project/10. 02_13_18/info.txt");
    istream_iterator<string> start(word_file), end;
    vector<string> words(start, end);
    cout << "\n\nwords as read\n";
    for(auto str: words) cout << str << " ";
    sort(words.begin(), words.end());
    cout << "\n\nwords as sorted\n";
    for(auto str: words) cout << str << " ";
    cout << endl;
}
