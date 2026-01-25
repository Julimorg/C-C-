//
// Created by acer on 1/21/2026.
//

#include "Struct1.h"
#include "iostream"

using namespace std;

struct sinhvien{
    int id;
    string name;
    float gpa;
};

int main(){


    sinhvien sv1;

    sv1.id = 1;
    sv1.name = "Fong";
    sv1.gpa = 4.0;

    sinhvien sv2 = {1002, "Tran Thi B", 9.0};



    cout << "Ma SV: " << sv1.id << endl;
    cout << "Ho ten: " << sv1.name << endl;

    int n;
    cin >> n;

    sinhvien sv3[100];

    for ( int i = 0 ; i < n; i++ ) {
        string name;
        cin >> name;
        float gpa ;
        cin >> gpa;
        sv3[i] = {i, name, gpa};
    }

    for (auto x : sv3){
        cout << sv3;
    }


    return 0;
}