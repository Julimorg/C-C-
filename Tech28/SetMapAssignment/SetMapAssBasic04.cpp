//
// Created by acer on 1/15/2026.
//

#include "SetMapAssBasic04.h"
#include "iostream"
#include "set"
#include "map"

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[n];
    for(int i = 0; i < n; i++ ) {
        cin >> a[i];
    }

    set<int> s;
    for(int i = 0 ; i < m ; i++) {
        int x ;
        cin >> x;
        s.insert(x);
    }

    for ( int i = 0 ; i < m; i++ ) {
        if ( s.count(a[i])) {
            cout << "28tech" << " ";
        } else {
            cout << "29tech" << " ";
        }
    }
    return 0;
}