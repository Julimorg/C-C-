//
// Created by jianf on 2/5/2026.
//

#include "Fibonacci_1.h"
#include "iostream"

using namespace std;

int fib(int n ) {
    if ( n <= 1) return n;
    // cout << "Print Fib: " << n << endl;
    return fib(n - 1) + fib(n - 2);
}
int fibonacci(int n ) {
    if ( n  <= 1) return n;

    int temp0 = 0;
    int temp1 = 1;
    int s = 0;

    for ( int i =  2; i <= n; i++ ) {
        s = temp0 + temp1;
        temp0 = temp1;
        temp1 = s;
        cout << "List fibancci: " << s << endl;
    }
    return s;
}

int main() {

    cout << "FIB: " << fibonacci(7) ;
    cout << endl;
    for (int i = 0; i <= 7; i++) {
        printf("F(%d) = %d\n", i, fib(i));
    }


    return 0;

}