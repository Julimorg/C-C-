//
// Created by acer on 1/4/2026.
//

#include "BasicMap.h"
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

int main() {
    map<int, string> my_map;

    cout << "input your n: " << endl;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++ ){

        string value;
        cout << "input student name: " << endl;
        cin >> value;

        my_map[i] = value;
    }

    for(auto x : my_map) {
        cout << x.first << ": " << x.second << endl;
    }

}
