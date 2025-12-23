#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, j, k;
        cin >> n >> j >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        if (k == 1) {
            int mx = *max_element(a.begin(), a.end());
            cout << (a[j-1] == mx ? "YES" : "NO") << '\n';
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
