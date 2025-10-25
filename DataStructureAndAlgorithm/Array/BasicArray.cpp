//
// Created by acer on 10/25/2025.
//

#include "BasicArray.h"
#include "iostream"
#include"iostream"
using namespace std;

int main(){
    int n = 10;
    int a[10] = {3, 2, 1, 4, 5, 8, 9, 7, 6, 10};
    cout << "Duyet thuan : ";
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << "\nDuyet nguoc : ";
    for(int i = n - 1; i >= 0; i--){
        cout << a[i] << " ";
    }
    char arr[10] = {'2', '8', 't', 'e', 'c', 'h'};
    cout << "\nMang char : ";
    for(int i = 0; i < 6; i++){
        cout << arr[i] << ' ';
    }
    return 0;
}