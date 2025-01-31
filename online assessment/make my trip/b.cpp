#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int MOD=1e9+7;
void solve(){
     int n, m;
    cin >> n >> m;
     int f[n+1];
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    
    if (f[1] == 0) {
        for (int j = 1; j <= m; ++j) {
            dp[1][j] = 1;
        }
    } else {
        dp[1][f[1]] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        if (f[i] == 0) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j > 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                if (j < m) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
            }
        } else {
            dp[i][f[i]] = dp[i-1][f[i]];
            if (f[i] > 1) dp[i][f[i]] = (dp[i][f[i]] + dp[i-1][f[i]-1]) % MOD;
            if (f[i] < m) dp[i][f[i]] = (dp[i][f[i]] + dp[i-1][f[i]+1]) % MOD;
        }
    }

 
    int ans = 0;
    for (int j = 1; j <= m; ++j) {
        ans = (ans + dp[n][j]) % MOD;
    }

    cout << ans << endl;
}

signed  main() {
   solve();
}