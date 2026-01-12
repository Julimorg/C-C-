//
// Created by acer on 1/12/2026.
//

#include "SetMapAss2.h"
#include "iostream"
#include "set"

using namespace std;

int main() {

    int n;
    cin >> n ;
    set<int> s;

    for (int i = 0; i < n; i++ ) {
        int value;
        cin >> value;
        s.insert(value);
    }

    int m;
    cin >> m;

    for(int i = 0 ; i < m ; i++ ) {
       int find;
       cin >> find;
       if ( s.find(find) != s.end()){
           cout << "YES" << endl;
       }else cout << "NO" << endl;
    }


    return 0;
}
