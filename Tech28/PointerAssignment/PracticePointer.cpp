//
// Created by kienp on 1/19/2026.
//

#include "PracticePointer.h"
#include "iostream"

using namespace std;

int main() {

    int x = 100;
    int *ptr = &x;

    //? Simple pointer
    cout << "Pointer's address is: " << ptr << endl;
    cout << "Pointer's value is: " << *ptr << endl;

    //? Null Pointer
    int *p = nullptr;
    if ( p == nullptr ) cout << "No pointer is defined." << endl;

    //? Void pointer
    void *v;
    v = &x;
    cout << "Pointer's value is: " << v << endl;
    cout << "Pointer's value is: " << *(int*)v  << endl;

    //? Wild Pointer

    int *w;
    cout << "Pointer's address is: " << w << endl;
    cout << "Pointer's value is: " << *w << endl;

    //? Array Pointer
    int a[5] = {1, 2, 3, 4};
    int *pa = a;
    cout << "Pointer's address is: " << pa << endl;
    cout << "Pointer's value is: " << *pa << endl;
    cout << "Pointer's next value is: " << *(pa + 1) << endl;
    return 0;
}