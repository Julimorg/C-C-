//
// Created by acer on 1/4/2026.
//

#include "PracticeSet1.h"
#include "bits/stdc++.h"
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {

    vector<int> vec = {412,100,12,5,12,315,2145,631,351711,125313,36,13,1,31435,3654,35,7454,2124,7786,344,5};

    // Convert vector sang set
    set<int> s1(vec.begin(), vec.end());

    cout << "Array goc : " << endl;

    for(int x : vec) {
        cout << x << " " ;
        cout << endl;
    };

    cout << " Array sau khi duoc convert sang set : " << endl;
    for ( int x : s1  ) {
        cout << x << " " ;
        cout << endl;
    };


    cout << "Dem so phan tu khac nhau trong Array : " << endl;
    vector<int> arr = {1, 2, 3, 2, 1, 4, 5, 4};
    set<int> s(arr.begin(), arr.end());

    cout << "So phan tu khac nhau: " << s.size() << endl;





    return 0;
}