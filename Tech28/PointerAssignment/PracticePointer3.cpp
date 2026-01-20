//
// Created by kienp on 1/20/2026.
//

#include "PracticePointer3.h"
#include "iostream"
using namespace std;

int main() {

    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    cout << "Arr : " ;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    arr = nullptr;



    return 0;
}