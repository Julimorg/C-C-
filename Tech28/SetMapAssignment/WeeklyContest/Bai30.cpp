//
// Created by acer on 1/19/2026.
//

#include <unordered_map>
#include "Bai30.h"
#include "iostream"
#include "set"
#include "map"
#include "vector"

using namespace std;

bool checkNum( int x) {
    if ( x == 0)  return true;
    while ( x > 0 ) {
        int d = x % 10;
        if (d != 0 && d != 2 && d != 6 && d != 8)
            return false;
        x /= 10;
    }
    return true;
}

int main() {

    int n ; cin >> n;
    unordered_map<int, int> m;
    vector<int> v;
    for ( int i = 0 ; i < n ; i++) {
        int x;
        cin >> x;
        if( checkNum(x)) {
            if ( m[x] == 0 ) {
                v.push_back(x);
            }
            m[x]++;
        }

    }

    for ( int x : v) {
        cout << x << " " << m[x] << "\n";
    }
    return 0;
}