//
// Created by acer on 1/15/2026.
//

#include "SetMapAssBasic03.h"
#include "iostream"
#include "set"
#include "map"

using namespace std;

int main() {
    int n;
    cin >> n;
    set<char> s;
    for ( int i = 0 ; i < n; i++ ){
        char c;
        cin >> c;
       s.insert(c);

    }
    cout << s.size() << endl;
    auto it_min = s.begin();
    auto it_second_min = next(s.begin());
    auto it_max = prev(s.end());
    auto it_second_max = prev(s.end(), 2);


    cout << *it_max << " "
         << *it_min << " "
         << *it_second_max << " "
         << *it_second_min << endl;

    return 0;
}