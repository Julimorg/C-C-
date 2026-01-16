//
// Created by acer on 1/16/2026.
//

#include "SetMapAss5.h"
#include "iostream"
#include "set"
#include "map"

using namespace std;

int main(){
    int n;
    cin >> n;

    map<char, int> m;

    for ( int i = 0; i < n ; i++ ){
        char c;
        cin >> c;
        m[c]++;
    }

    auto smallest = m.begin();
    cout << smallest->first << " " << smallest->second << "\n\n";

    auto biggest = m.rbegin();
    cout << biggest->first << " " << biggest -> second << "\n\n";

    for ( auto x : m ) {
        cout << x.first << " " << x.second << "\n";
    }
    cout << "\n";


    for ( auto i = m.rbegin(); i != m.rend(); i++ ){
        cout << i -> first << " " << i -> second << "\n";
    }




    return 0;
}