//
// Created by jianf on 2/5/2026.
//

#include "Fibonacci_1.h"
#include "iostream"

using namespace std;

// O ( 2 ^ N )
int fib(int n ) {
    if ( n <= 1) return n;
    // cout << "Print Fib: " << n << endl;
    return fib(n - 1) + fib(n - 2);
}
int fun (int n)

{

    int x=1, k;

    if (n==1) return x;

    for (k=1; k<n; ++k)

        x=x + fun (k) * fun (n - k);

    return x;

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

void count(int n)

{

    static int d = 1;

    printf("%d", n);

    printf("%d", d);

    d++;

    if (n > 1) count (n-1);

    printf("%d", d);

}

int main() {

    cout << "FIB: " << fibonacci(7) ;
    cout << endl;
    // for (int i = 0; i <= 50; i++) {
    //     printf("F(%d) = %d\n", i, fib(i));
    // }
    cout << fun(5);

    cout <<  endl;
    count (3);

    return 0;

}