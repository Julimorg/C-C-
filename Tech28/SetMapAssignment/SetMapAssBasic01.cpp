//
// Created by acer on 1/12/2026.
//

#include "SetMapAssBasic01.h"
#include "iostream"
#include "map"
#include "set"

using namespace std;

int main() {

    int n;
    cin >> n ;
    set<int> s;

    for (int i = 0 ; i < n ; i++) {
        int value;
        cin >> value;

        s.insert(value);
    }
    cout << s.size() << endl;
    for (int x : s ){
        cout << x << " ";
    }


    return 0;
}