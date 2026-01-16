//
// Created by acer on 1/16/2026.
//

#include "SetMapAssBasic07.h"
#include "iostream"
#include "set"
#include "map"

using namespace std;

int main() {

    int n;
    cin >> n;
    map<int, int> m;
    for ( int  i = 0 ; i < n; i ++) {
        int v;
        cin >> v;
        m[v]++ ;
    }

    for ( auto x : m) {
        cout << x.first << " " << x.second << "\n";
    }






    return 0;
}
