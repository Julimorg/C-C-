//
// Created by acer on 1/28/2026.
//

#include "Recursion1.h"
#include "iostream"
using namespace std;

void func(int n) {
    if ( n > 0) {
        func ( n - 1 );
        cout << "n: " << n;
    }
}

void sum( int n) {
    int totalSum = 0;
    if ( n > 0) {
        totalSum += n;
        cout << "totalSUm:" << totalSum;
        sum(n-1);
    }
}
int main(){
    func(3);
    cout << endl;
    sum(3);

    return 0;
}