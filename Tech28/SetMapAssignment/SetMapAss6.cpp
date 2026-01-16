//
// Created by acer on 1/15/2026.
//

#include "SetMapAss6.h"
#include "iostream"
#include "set"

using namespace std;

int main() {
    int n;
    cin >> n;
    set<pair<int,int>> s;
    for(int i = 0 ; i < n; i++) {
        int x,y;
        cin >> x >> y;
        s.insert({x,y});

    }
    cout << s.size();
}
