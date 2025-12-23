#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    // Key insight: The last element cannot be changed by any operation
    // So if a[n-1] != b[n-1], it's impossible
    if (a[n-1] != b[n-1]) {
        cout << "NO" << endl;
        return;
    }
    
    // Work backwards from right to left
    // For each position i, we can either:
    // 1. Keep a[i] as is
    // 2. Change a[i] to a[i] ^ a[i+1]
    
    vector<int> curr = a;
    
    for (int i = n-2; i >= 0; i--) {
        if (curr[i] == b[i]) {
            // Already matches, don't apply operation
            continue;
        } else if ((curr[i] ^ curr[i+1]) == b[i]) {
            // Can achieve target by applying operation
            curr[i] = curr[i] ^ curr[i+1];
        } else {
            // Cannot achieve target value
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}