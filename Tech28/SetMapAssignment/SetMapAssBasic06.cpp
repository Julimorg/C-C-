//
// Created by acer on 1/16/2026.
//

#include "SetMapAssBasic06.h"
#include "iostream"
#include "set"
#include "map"

using namespace std;
int main(){

    int n;
    cin >> n;
    set<string> s;

    for(int i = 0 ; i < n ; i++ ) {
        string m;
        cin >> m;
        s.insert(m);
    }
    cout << s.size() << endl;
    for ( string x : s) {
        cout << x << " ";
    }


    return 0;
}