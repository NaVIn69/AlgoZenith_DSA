#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];
int dp[100100];
int rec(int level){

   if(level==0){
    return 0;
   }

   if(level<0){
    return 1e18;
   }

   if(dp[level] != -1) return dp[level];

   int ans=1e18;
   for(int i=1;i<=k;i++){

      if(level-i>=0){
      ans=min(ans,rec(level-i)+abs(arr[level]-arr[level-i]));
      }

   }

   return dp[level]=ans;
}
void solve(){
  cin>>n>>k;
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<rec(n-1)<<endl;
//   for(int i=0;i<n;i++) cout<<dp[i]<<" ";

}
signed main(){
    solve();
}
