#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    vector<vector<int>>pos(n+1);
    for(int i=1;i<=n;i++){
        pos[arr[i]].push_back(i);
    }
    vector<vector<pair<int,int>>>edges(n+1);
        for (int i=1;i<=n;i++) {
            vector<int>p=pos[i];
            int m=p.size();
            if(m>=i) {
                // For each window of size v among occurrences, add minimal interval
                for (int t=0;t+i-1<m;t++) {
                    int L=p[t];
                    int R=p[t+i-1];
                    edges[R].push_back({L,i});
                }
            }
        }

        vector<int>dp(n+1,0);
        for (int i=1;i<=n;i++) {
            dp[i]=dp[i-1]; // skip i
            for (auto &e:edges[i]) {
                int L=e.first;
                int v=e.second;
                dp[i]=max(dp[i],dp[L-1]+v);
            }
        }
        cout<<dp[n]<<endl;

   

}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}