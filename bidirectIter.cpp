#include <iostream>
using namespace std;

template<typename Bidirectional>
bool isPalindrome(Bidirectional first, Bidirectional last){
    while(true){
        last--;
        if(first == last)
            break;
        if(*first != *last)
            return false;
        first++;
        if(first == last)
            break;
    }
    return true;
}
