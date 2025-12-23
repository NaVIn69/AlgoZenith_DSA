#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<ll> pref(n+1);
        pref[0] = 0;
        for (int i = 0; i < n; i++) pref[i+1] = pref[i] + a[i];

        // Binary search on h
        ll low = 1;
        // Upper bound: if all columns are 1 and x is up to 1e9, h can go up to max(a) + x
        ll high = a.back() + x + 1; 
        ll ans = 1;
        while (low <= high) {
            ll mid = low + ((high - low) >> 1);
            // count of a[i] < mid
            int cnt = upper_bound(a.begin(), a.end(), mid - 1) - a.begin();
            // water needed: cnt * mid - sum of those cnt elements
            // watch overflow
            ll need = (ll)cnt * mid - pref[cnt];
            if (need <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
