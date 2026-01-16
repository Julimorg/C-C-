//
// Created by acer on 1/15/2026.
//

#include "SetMapAss8.h"
#include "iostream"
#include "set"
using namespace  std;

int main(){

    int n;
    cin >> n;
    multiset<int> s;
    for(int i = 0 ; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    int q;
    cin >> q;
    while (q--) {
        
    }
    auto max = s.begin();
    auto min = prev(s.end());
    cout << *max << " ";
    cout << *min << " ";


    return 0;
}
