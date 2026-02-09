//
// Created by jianf on 2/9/2026.
//

#include "ArrayADT.h"
#include "iostream"

using namespace std;

struct Array {
    int *A;
    int size;
    int length;
};

typedef struct Array Array;

void Display(Array array) {
    cout << "Elements are: " << endl;
    for (int i = 0; i < array.length; i++) {
        cout << array.A[i] << " ";
    }
}

void insertValue(Array *arr , int index, int value) {
    int i ;
    for (i = arr->length ; i > index ; i--) {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[i] = value;
    arr->length++;
}
void deleteValue( Array *arr, int index) {
    int x = 0;
    int  i ;
    if ( index >= 0 && index < arr->length) {
        x = arr->A[index];
        for ( i = index; i < arr->length - 1 ; i++) {
            arr->A[i] = arr->A[i+1];

        }
        arr->length--;
        // return x;
    }
    cout << "x is: " << x;
    // return 0;
}

int main() {

    Array array;
    int n, i;
    cout << " Enter size of an array: " <<  endl;
    cin >> array.size;
    array.A = new int;
    array.length = 0;

    cout << "Enter number of numbers:  " << endl;
    cin >> n;

    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> array.A[i];
    }
    array.length = n;

    Display(array);

    cout << endl;

    insertValue(&array, 3, 200);

    cout << "Array after insert is : " << endl;

    Display(array);

    cout << endl;

    deleteValue(&array, 4);

    cout << "Array after delete is : " << endl;

    Display(array);


    return 0;
}