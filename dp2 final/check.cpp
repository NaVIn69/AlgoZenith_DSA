#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod = 1e9 + 7;
int n, k;
int arr[105];
int dp[105][100100]; // Memoization table

// Recursive function with memoization and prefix sum optimization
int rec(int i, int left) {
    // Base case: if we have distributed all candies to all children
    if (i == n) {
        return left == 0 ? 1 : 0; // If no candies are left, one valid way
    }

    // If we already calculated this subproblem, return the cached result
    if (dp[i][left] != -1) {
        return dp[i][left];
    }

    int ans = 0;
    // We will use prefix sum to calculate this efficiently
    int prefix_sum = 0;

    // Try giving from 0 to arr[i] candies to the ith child
    for (int ch = 0; ch <= min(arr[i], left); ch++) {
        prefix_sum = (prefix_sum + rec(i + 1, left - ch)) % mod;
    }

    // Store the result in dp and return it
    return dp[i][left] = prefix_sum;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize the memoization table with -1 (unvisited state)
    memset(dp, -1, sizeof(dp));

    // Start the recursive process
    cout << rec(0, k) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
