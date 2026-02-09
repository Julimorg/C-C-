//
// Created by jianf on 2/7/2026.
//

#include "Array2D.h"
#include "iostream"

using namespace std;

int main() {

    int a[3][4] = {{1,2,3,1}, {312,312,312,1}, {354,12,43,32}};

    for ( int i = 0 ; i < 3 ; i++ ) {
        for ( int j = 0 ; j < 4 ; j++ ) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


    cout << "=======================" << endl;
    int *b[3];
    b[0] = new int [1];
    b[1] = new int [2];
    b[2] = new int [3];

    for ( int i = 0 ; i < 3 ; i++ ) {
        for ( int j = 0 ; j < 4 ; j++ ) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    int **c;
    c = new int *[3];
    c[0] = new int [1];
    c[1] = new int [2];
    c[2] = new int [3];
    // for ( int i = 0 ; i < 3 ; i++ ) {
    //     for ( int j = 0 ; j < 4 ; j++ ) {
    //         cout << c[i][j] << " ";
    //     }
    // }

    return 0;
}