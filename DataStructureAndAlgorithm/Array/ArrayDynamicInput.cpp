//
// Created by acer on 10/25/2025.
//

#include "ArrayDynamicInput.h"
#include <iostream>
using namespace std;

int main(){
    //Lưu ý là mảng a chỉ lưu được tối đa 1000 phần tử
    int n;
    cout << "Nhap n : ";
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    cout << "Mang vua nhap : ";
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}