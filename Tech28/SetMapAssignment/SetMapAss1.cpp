//
// Created by acer on 1/12/2026.
//

#include <vector>
#include <set>
#include "SetMapAss1.h"
#include "iostream"

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    for ( int i = 0 ; i < n; i++) {
        int number;
        cin >> number;
        s.insert(number);
    }
    cout << s.size();

   return 0;
}