#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n, q; 
    cin >> n >> q;

    vector<int> arr(n);
    unordered_map<int,int> freq;  // value -> count
    long long distinctPos = 0;     // number of distinct values > 0

    auto addVal = [&](int x) {
        // increase freq and possibly distinctPos
        int &f = freq[x];
        if (x > 0 && f == 0) distinctPos++;
        f++;
    };

    auto removeVal = [&](int x) {
        int &f = freq[x];
        f--;
        if (x > 0 && f == 0) distinctPos--;
        if (f == 0) freq.erase(x);
    };

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        addVal(arr[i]);
    }

    while (q--) {
        int op; 
        cin >> op;
        if (op == 1) {
            int p, v; 
            cin >> p >> v; 
            --p;
            removeVal(arr[p]);
            arr[p] = v;
            addVal(v);
        } else { 
            cout << distinctPos << endl; // min ops = #distinct positive values
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) solve();
    return 0;
}
