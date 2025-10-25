//
// Created by acer on 10/25/2025.
//

#include "ArrayDefaultInput.h"
#include <iostream>
using namespace std;

int main(){
    //Lưu ý là mảng a chỉ lưu được tối đa 1000 phần tử
    int n, a[1000];
    cout << "Nhap n : ";
    cin >> n;
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