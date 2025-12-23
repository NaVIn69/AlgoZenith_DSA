#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; 
        cin >> n;
        unordered_map<long long, long long> freq;
        freq.reserve(n * 2);

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++freq[a[i]];
        }

        long long ans = 0;
        for (auto &p : freq) {
            long long x = p.first;
            long long c = p.second;
            ans = max(ans, x + c - 1);
        }

        cout << ans << "\n";
    }
    return 0;
}
