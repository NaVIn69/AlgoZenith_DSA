#include <bits/stdc++.h>
    using namespace std;
    #define int long long
    const int INF = LLONG_MAX;
    
    void solve() {
        int n;
        cin >> n;
    
        int G_min = INF;
        vector<int> secondMin(n);
        
  
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;
            int mn1 = INF, mn2 = INF;
            for (int j = 0; j < m; ++j) {
                int x; 
                cin >> x;
                if (x < mn1) {
                    mn2 = mn1;
                    mn1 = x;
                }
                else if (x < mn2) {
                    mn2 = x;
                }
            }
            if (mn2 == INF) mn2 = mn1; 
            secondMin[i] = mn2;
            G_min = min(G_min, mn1);        
        }

        int sum2 = 0;
        for (int v : secondMin) sum2 += v;
    
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, G_min + (sum2 - secondMin[i]));
        }
    
        cout << ans << "\n";
    }
    
    signed main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    
        int T; 
        cin >> T;
        while (T--) solve();
        return 0;
    }
    
    