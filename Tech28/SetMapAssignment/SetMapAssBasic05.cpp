//
// Created by acer on 1/16/2026.
//

#include "SetMapAssBasic05.h"
#include "iostream"
#include "set"
#include "map"

using namespace std;

int main() {

    int n,m;
    cin >> n >> m;
    multiset<int> s;

    int a[n];
    for(int i = 0 ; i < n; i++ ){
        cin >> a[i];
    }

    for(int i = 0 ;  i < m ; i++ ){
        int x;
        cin >> x;
        s.insert(x);
    }

    for ( int i = 0; i < n ; i++ ){
        cout << s.count(a[i]);
        if(i < m - 1) cout << " ";
    }


    return 0;
}