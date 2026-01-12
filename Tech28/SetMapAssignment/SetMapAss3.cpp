//
// Created by acer on 1/12/2026.
//

#include <unordered_set>
#include <vector>
#include "SetMapAss3.h"
#include "iostream"
#include "set"


using namespace std;


int main () {

    int n ;
    cin >> n ;
    set <int> s;

    for (int i = 0 ; i < n; i++ ) {
        int number;
        cin >> number;

        if (s.find(number) == s.end()){
            cout << number << " ";
            s.insert(number);
        }
    }

    return 0;
}