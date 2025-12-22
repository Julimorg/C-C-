//
// Created by acer on 12/22/2025.
//

#include "BasicVector.h"
#include "iostream"
#include "bits/stdc++.h"
using namespace std;

int main(){
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << v.size() << endl;

    v.push_back(40);

    cout << v.size() << endl;

    cout << "First index: " << v[0] << endl;

    cout << "Last index: " << v[v.size() - 1] << endl;

    cout << "Last Index : " << v.back() << endl;


    //* For loop with iterator
    for( vector<int>::iterator it = v.begin(); it != v.end(); ++it){
        cout << *it << endl;
    }

    //* Auto for iterator
    for(auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    }

    //* Foreach
    for(int x : v) {
        cout << x << endl;
    }
    return 0;
}