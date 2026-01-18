//
// Created by acer on 1/16/2026.
//

#include "SetMapAssBasic08.h"
#include "iostream"
#include "set"
#include "map"
#include "vector"

using namespace std;

int main() {
    int n ;
    cin >> n ;
    vector<int> v;
    map<int, int> m;

    for ( int i = 0 ; i < n ; i ++) {
        int value;
        cin >> value;

        if ( m[value] == 0 ) {
            v.push_back(value);
        }
        m[value]++;
    }

    for ( int x : v) {
        cout << x <<  "  " << m[x] << "\n";
    }
    return 0;
}