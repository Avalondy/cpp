#include <iostream>
#include "studentInhe.h"
using namespace std;

int main(){
    student s("Mae Pohl", 100, 3.425, student::fresh), *ps = &s;
    grad_student gs("Morris Pohl", 200, 3.2564, student::grad, grad_student::ta,
            "Pharmacy", "Retail Pharmacies"), *pgs;
    ps->print();
    ps = pgs = &gs;
    ps->print();
    pgs->print();
}

/*
Mae Pohl, 100, 0, 3.425
Morris Pohl, 200, 4, 3.2564
Morris Pohl, 200, 4, 3.2564
Pharmacy, 0
Retail Pharmacies
*/
