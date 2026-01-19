//
// Created by kienp on 1/19/2026.
//

#include "PracticePointer2.h"
#include "iostream"
using namespace std;

int compare(int a, int b, int *larger ) {
    if ( a > b ) {
        return *larger = a;
    } else {
        return *larger = b;
    }
}

void swap ( int *x, int *y ) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void calculate ( int x, int y, int *tong, int *hieu) {
    *tong = (x+y);
    *hieu = (x-y);
    cout << "Tong: " << *tong << endl;
    cout << "Hieu: " << *hieu << endl;
}

int sumArray( int *arr, int n) {
    int sum = 0;
    for ( int i = 0 ; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int findMax( int *arr, int n) {
    int max = arr[0];
    for ( int i = 0 ; i < n; i++) {
        if ( max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int countEven(int *arr, int n) {
    int count = 0 ;
    for ( int i = 0 ; i < n; i++) {
        if ( arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int reverseArray( int *arr, int n) {
   int *start = arr;
    int *end = arr + n - 1;
    while ( start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
int main() {

    // Bai 1
    int x = 50;
    int *ptr;
    ptr = &x;
    cout << "Address x is : " << &x << endl;
    cout << "Address p is: " << ptr << endl;
    cout << "Value x is: " << *ptr << endl;

    // Bai 2
    int a = 10;
    int *p;
    p = &a;
    cout << "Value a is: " << *p << endl;
    *p = 99;
    cout << "Value a is: " << *p << endl;


    // Bai 3
    int result;
    compare(5, 10, &result);
    cout << "Result is : " << result << endl;

    // Bai 4
    int z = 7;
    int b = 3;
    swap(&z, &b);

    cout << "Value a is: " << a << " Value b is: " << b << endl;

    // Bai 5
    int tong, hieu;
    calculate(10, 3, &tong, &hieu);

    // Bai 6
    int arr[5] = {2, 4, 6, 8, 10};
    int  *parr = arr;
    for ( int i = 0 ; i < 5; i++) {
        cout << parr[i] << " ";
    }

    // Bai 7
    int arr2[] = {1, 2, 3, 4, 5};
    int total = sumArray(arr2, 5);
    cout << "Total is: " << total << endl;

    // Bai 8
    int arr3[] = {3, 7, 2, 9, 1};
    int max = findMax(arr3, 5);
    cout << "Max is: " << max << endl;

    // Bai 9
    int arr4[] = {1, 2, 3, 4, 5, 6};
    int count = countEven(arr4, 6);
    cout << "Count is: " << count << endl;

    // Bai 10
    int arr5[] = {1, 2, 3, 4, 5};
    reverseArray(arr5, 5);
    for (int i = 0; i < 5; i++) {
        cout << arr5[i] << " ";
    }
    return 0;
}