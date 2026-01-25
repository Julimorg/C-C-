//
// Created by acer on 1/24/2026.
//

#include "PracticePointer4.h"
#include "iostream"
using namespace std;
int main(){

    int a[6] = {1,3,5,7,9,11};

    for ( int i = 0 ; i < 6; i++){
        for ( int j = 0 ; j < 6; j++){
            if ( a[j] + a[i] == 16) {
                cout << "i: " << a[i] << " + j: "  << a[j] << " = 16" << endl;
            }
        }
    }
    return 0;
}