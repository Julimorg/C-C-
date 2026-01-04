//
// Created by acer on 1/4/2026.
//

#include "PraticeMultiSet.h"
#include <iostream>
#include <set>
#include <vector>
using namespace std;

double findMedian(multiset<int>& ms) {
    int n = ms.size();
    auto it = ms.begin();
    advance(it, n / 2);

    if(n % 2 == 1) {
        return *it;
    } else {
        int a = *it;
        --it;
        int b = *it;
        return (a + b) / 2.0;
    }
}

vector<int> kLargest(vector<int>& arr, int k) {
    multiset<int> ms(arr.begin(), arr.end());
    vector<int> result;

    auto it = ms.rbegin();
    for(int i = 0; i < k && it != ms.rend(); i++, it++) {
        result.push_back(*it);
    }

    return result;
}

int main () {
    vector<int> arr = {5, 2, 8, 2, 9, 5, 2};
    multiset<int> ms(arr.begin(), arr.end());

    cout << "========== Tan suat xuat hien ==========" << endl;
    set<int> unique(arr.begin(), arr.end());

    for(int x : unique) {
        cout << x << " xuat hien " << ms.count(x) << " lan" << endl;
    }



    cout << "========== Tim trung vi ==========" << endl;

    multiset<int> ms2 = {5, 2, 8, 2, 9};
    // Sau khi sắp xếp: {2, 2, 5, 8, 9}

    cout << "Median: " << findMedian(ms2) << endl;

    ms.insert(10);
    cout << "Median: " << findMedian(ms) << endl;


    cout << "========== K phan tu lon nhat ==========" << endl;
    vector<int> arr1 = {5, 2, 8, 2, 9, 5, 10};
    vector<int> top3 = kLargest(arr1, 3);

    cout << "3 phan tu lon nhat: ";
    for(int x : top3) cout << x << " ";
    cout << endl;

}
