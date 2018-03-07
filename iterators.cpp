#include <iostream>
#include <cstddef>
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

template<typename RandomAccess>
RandomAccess pickRandEI(RandomAccess first, RandomAccess last){
    ptrdiff_t temp = last - first;
    return first + rand() % temp;
}
