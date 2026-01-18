//
// Created by acer on 1/17/2026.
//

#include "Prefix2.h"
#include "iostream"
#include "vector"

using namespace std;

vector<int> buildPrefix(const vector<int>& a){
    int n = a.size();
    vector<int> prefix(n);

    prefix[0] = a[0];

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    return prefix;
}

int rangeSum(const vector<int>& prefix, int L, int R) {
    if (L == 0) return prefix[R];
    return prefix[R] - prefix[L - 1];
}


int main() {

    vector<int> a = {1,2,34,3,1,2,3,1,2,3,1,2};

    vector<int> prefix = buildPrefix(a);

    cout << rangeSum(prefix, 2, 5) << endl;
    cout << rangeSum(prefix, 0, 6) << endl;
    cout << rangeSum(prefix, 3, 3) << endl;

    return  0;
}

