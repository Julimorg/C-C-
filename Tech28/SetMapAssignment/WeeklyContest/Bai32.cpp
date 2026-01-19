//
// Created by acer on 1/19/2026.
//

#include "Bai32.h"
#include "iostream"
#include "set"
#include "vector"

using namespace std;

int main() {

    int n;
    cin >> n;
    set<char> s;

    for ( int i = 0 ; i < n ; i++) {
        char c;
        cin >> c;
        s.insert(c);
    }

    cout << s.size() << "\n";

    for ( auto i = s.rbegin(); i != s.rend(); i++){
        cout << *i << " " ;
    }




    return 0;
}