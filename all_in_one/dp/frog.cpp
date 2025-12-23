#include<bits/stdc++.h>
using namespace std;

int n,k;
int arr[100100];

int dp[100100];

// fn ->this will give me the minimum cost to reach from level to n 
int rec(int level){
   if(level==n){
       return 0;
   }
   if(level>n){
       return 1e9+7;
   }
   if(dp[level]!=-1){
      return dp[level];
   }
   // transection
   // here we have k choice to move on the level to level+i(1....k)
   int ans=1e9+7;
   for(int i=1;i<=k;i++){
       if(level+i<=n){
        ans=min(ans,(abs(arr[level]-arr[level+i])+rec(level+i)));
       }else{
        break;
       }
   
   }
   return dp[level]=ans;

}
void solve(){
  cin>>n>>k;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
  }
  memset(dp,-1,sizeof(dp));
  cout<<rec(1)<<endl;
//   for(int i=1;i<=n;i++){
//     cout<<dp[i]<<" ";
//   }
//   cout<<endl;

}
int main(){
    solve();
}