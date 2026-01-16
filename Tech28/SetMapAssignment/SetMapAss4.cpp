//
// Created by acer on 1/16/2026.
//

#include "SetMapAss4.h"
#include "iostream"
#include "set"
#include "map"

using namespace std;

int main() {

    int n;
    cin >> n;

    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }

    int q;
    cin >> q;
    while(q--) {
        int type, x;
        cin >> type >> x;

        if(type == 1) {
            mp[x]++;
        }
        else if(type == 2) {
            if(mp[x] > 0) {
                mp[x]--;
            }
        }
        else if(type == 3) {
            if(mp[x] > 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}