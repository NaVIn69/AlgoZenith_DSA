#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n,m;
char grid[1005][1005];
int dp[1005][1005];
int rec(int i,int j){
  // this gives me the total number of path from (i,j) to the (n,m)
  if(i>=n||j>=m) return 0;
  if(grid[i][j]!='#'&&i==n-1&&j==m-1){
    return 1;
  }
  if(grid[i][j]=='#'){
    return 0;
  }

  // cache check
  if(dp[i][j]!=-1){
    return dp[i][j];
  }
  int ans=0;
  if(grid[i+1][j]!='#'){
    ans=ans%mod+rec(i+1,j)%mod;
  }
   if(grid[i][j+1]!='#'){
    ans=ans%mod+rec(i,j+1)%mod;
  }
  return dp[i][j]=ans;
}
void solve(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>grid[i][j];
        // cout<<grid[i][j];
    }
    // cout<<endl;
  }
  memset(dp,-1,sizeof(dp));
  int ans=rec(0,0);
  cout<<(rec(0,0)%mod+mod)%mod<<endl;
  
}
signed main(){
  solve();
}