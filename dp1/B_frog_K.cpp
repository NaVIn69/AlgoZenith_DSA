#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int h[100100];
vector<int>dp;
int rec(int level){
    // base case
    // 0 se 0 pe janne ka cost 0
    if(level==0) return 0;

      // cache check
     if(dp[level]!=-1){
        return dp[level];
     }

     //transition
     dp[level]=0;
    for(int i=1;i<=k;i++){
       dp[level]=min(dp[level])
    }
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    dp.resize(n+1,-1);
   int ans = rec(n-1);
     cout<<dp[n-1]<<endl;





}
signed main(){
    solve();
}