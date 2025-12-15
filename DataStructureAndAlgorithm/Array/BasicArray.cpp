//
// Created by acer on 10/25/2025.
//

#include "BasicArray.h"
#include "iostream"
#include"iostream"
using namespace std;

int main(){

    cout << " ==================== PHAN 1: KHAI BAO ARRAY ==================== " << endl;


    //? Cách 1: Khai báo rồi gán từng giá trị
    int arr1[5];

    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    arr1[3] = 4;
    arr1[4] = 5;

    cout << " 1 Loop Arr1[5] " << endl;

    cout << " - 1.1 : While Loop " << endl;

    int i1 = 0;
    while ( i1 < 5 ) {
        cout << arr1[i1] << endl;
        i1++;
    }

    cout << " - 1.2: For Loop " << endl;
    for( int i = 0 ; i < 5 ; i++ ) {
        cout << arr1[i] << endl;
    }


    // Cách 2: Khởi tạo ngay khi khai báo

    int arr2[5] = {1,2,3,4,5};

    cout << " 2 Loop Arr2[5] " << endl;

    cout << " - 2.1 For Loop " << endl;
    for( int i = 0 ; i < 5; i++) {
        cout << arr2[i] << endl;
    }

    // Cách 3: Khởi tạo một phần (phần còn lại tự động = 0)

    int arr3[5] =  { 1, 2,3};

    cout << " 2 Loop Arr3[5] " << endl;

    cout << " - 3.1 For Loop " << endl;
    for( int i = 0 ; i < 5; i++) {
        cout << arr3[i] << endl;
    }

    // ==========================================
    // PHẦN 2: NHẬP VÀ XUẤT MẢNG
    // ==========================================
    cout << "========== PHAN 2: NHAP XUAT MANG ==========" << endl;

    int n ;
    int a[100]; // Khai báo Array đủ lớn

    cout << "Input N: ";
    cin >> n;

    cout << "Input " << n << " element : " << endl;
    for( int i = 0 ; i < n ; i++ ) {
        cout << " a[ " << i << " ] = ";
        cin >> a[i];
    }

    cout << "Out put Array: " ;
    for(int i = 0 ; i < n ; i++) {
        cout << " a [ " << i << " ] = " << a[i] << endl;
    }

    cout << endl << endl;

    // ==========================================
    // PHẦN 3: TÍNH TỔNG CÁC PHẦN TỬ
    // ==========================================

    cout << "========== PHAN 3: TINH TONG ==========" << endl;

    cout << " Tinh tong da cho truoc" << endl;
    int arrSum1[10] = {1,2,3,4,5,6,7,8,9,10};

    int sum1 = 0;
    for( int i = 0 ; i < 10 ; i++ ) {
        sum1 += arrSum1[i];
    }
    cout << "Output: " << sum1;

    cout << " Tinh tong tu nhap so " << endl;
    int nSum;
    int arrSum2[100];

    cout << "Input N : " ;
    cin >> nSum;

    cout << "Nhap Array de tinh tong " << endl;
    for( int i = 0 ; i < nSum; i++) {
        cout << "a [" << i << "] =" ;
        cin >> arrSum2[i];
    }

    int sum2 = 0;
    for( int i = 0 ; i < nSum ; i++ ) {
        sum2 += arrSum2[i];
    }

    cout << "Output : " << sum2;

    // ==========================================
    // PHẦN 5: TÌM PHẦN TỬ LỚN NHẤT
    // ==========================================

    cout << " Tim Max " << endl;
    int nMax;
    int arrMax[100];

    cout << "Input N : " ;
    cin >> nMax;

    cout << "Nhap Array de tim MAX " << endl;
    for( int i = 0 ; i < nMax; i++) {
        cout << "a [" << i << "] =" ;
        cin >> arrMax[i];
    }


    cout << " Cach tu suy nghi la so sanh lien ke " << endl;
    int MAX1 = arrMax[0];
    for ( int i = 0 ; i < nMax - 1 ; i++ ){
        if ( arrMax[i] > arrMax[i+1])
        {
            if ( arrMax[i] > MAX1 ){
                MAX1 = arrMax[i];
            }
        }else {
            if (arrMax[i + 1] > MAX1 ) {
                MAX1 = arrMax[i + 1];
            }
        }
    }

    cout << " Output Max voi cach 1: " << MAX1 << endl;


    cout << " Find Max Cach 2 " << endl;

    int MAX2 =  arrMax[0];
    int vitriMax = 0;
    for ( int i = 0 ; i < nMax ; i++ ){
        if ( arrMax[i] > MAX2)
            {
                MAX2 = arrMax[i];
                vitriMax = i;
            }
    }

    cout << "Output Max voi cach 2: " << MAX2 << " vi tri max: " << vitriMax;






    return 0;
}