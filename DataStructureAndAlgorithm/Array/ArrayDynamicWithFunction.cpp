#include <bits/stdc++.h>



typedef long long ll;



using namespace std;



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int n;

    cin >> n;

    set<int> se;

    for (int i = 0; i < n; i++)

    {

        int x;

        cin >> x;

        se.insert(x);

    }

    cout << se.size();

    return 0;

}