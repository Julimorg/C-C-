//
// Created by acer on 10/25/2025.
//

#include "ArrayDynamicWithFunction.h"
#include "iostream"
using namespace std;

void input(int a[], int n){
    for(int i = 0;  i<=n ; i++){
        cout << "a[" << i << "] = ";g
        cin >> a[i];
    }
}

int output(int a[], int n) {
    cout << "Mang vua nhap : ";
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

int main(){
    int n, a[n];
    printf("Nhap n : ");
    cin >> n;
    input(a, n);
    output(a, n);
    return 0;
}