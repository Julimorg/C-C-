//
// Created by acer on 1/16/2026.
//

#include "Prefix1.h"
#include "iostream"
#include "vector"
using namespace  std;

int main() {
    vector<int> a = {1,2,34,3,1,2,3,1,2,3,1,2};
    int n = a.size();
    vector<int> prefix(n);
    cout << prefix[1] << "\n";
    cout << prefix[0] << "\n";
    cout << prefix[2] << "\n";
    prefix[0] = a[0];
    cout << prefix[1] << "\n";
    cout << prefix[0] << "\n";
    cout << prefix[2] << "\n";
    for ( int i = 1 ; i < n ; i++) {
        prefix[i] = prefix[i - 1]  + a[i];
    }
    cout << prefix[1] << "\n";
    cout << prefix[0] << "\n";
    cout << prefix[2] << "\n";
    cout << "Original Array: ";
    for ( int i = 0 ; i < n; i++ ){
      cout << a[i] << " " ;
    }
    cout << "\n";

    cout << "Prefix Array: ";
    for (int i = 0; i < n; i++) {
        cout << prefix[i] << " ";
    }

    cout << "\n";

    cout << "Prefix Array: ";
    for(int x : a){
        cout  << prefix[x] << " ";
    }

    int l, r;
    cin >> l >> r;

    if ( l == 0) cout << prefix[r];

    cout << prefix[r] - prefix[l-1];

    return 0;
}
