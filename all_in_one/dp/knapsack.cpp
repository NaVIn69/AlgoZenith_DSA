#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,w;
int wt[101];
int val[101];
int dp[101][100010];

// this function gives me the maximum value sum from level to n-1 by taking wlft
int rec(int level,int wleft){
    // base case 
    if(level==n){
        return 0;
    }
    // cache
    if(dp[level][wleft]!=-1){
        return dp[level][wleft];
    }

    // here we have to choice take or dont take
    int ans=0;
    // take it
    if(wt[level]<=wleft){
       ans=max(ans, val[level]+rec(level+1,wleft-wt[level]));
    }
    // dont take it 
    ans=max(ans,rec(level+1,wleft));
    return dp[level][wleft]=ans;
}
void solve(){
  cin>>n>>w;
  for(int i=0;i<n;i++){
    cin>>wt[i]>>val[i];
  }
  memset(dp,-1,sizeof(dp));
  cout<<rec(0,w)<<endl;

}
signed main(){
    solve();
}
