#include <bits/stdc++.h>
using namespace std;

int main() {
 
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        if (n == 1) {
            cout << a[0] << "\n";
            continue;
        }

        if (n == 2) {
            cout << a[0] + a[1] << "\n";
            continue;
        }

        sort(a.begin(), a.end());
        cout << a[0] + a[n - 1] << "\n";
    }

    return 0;
}
