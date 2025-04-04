 #include <bits/stdc++.h>
using namespace std;
#define int long long
   int MOD = 1e9 + 7;
void solve(){
       int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    vector<map<int, int>> s(n); // Stores (jump -> count) for each index

    // Read queries and mark start points
    for (int i = 0; i < q; i++) {
        int start, jump;
        cin >> start >> jump;
        s[start][jump]++; // Register query at 'start' with step 'jump'
    }

    int totalSum = 0;

    // Process the array
    for (int i = 0; i < n; i++) {
        for (auto &[jump, count] : s[i]) {
            totalSum = (totalSum + A[i] * count) % MOD;
            if (i + jump < n) {
        s[i + jump][jump] += count; // Propagate count
            }
        }
    }

    cout << totalSum << "\n";
}

signed main() {
 solve();
}