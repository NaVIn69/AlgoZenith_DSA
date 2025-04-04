// form 2 
// dp(i) give me maximum total happiness upto ith index
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100][4];
int dp[100100][4];
int rec(int level,int prev){
  // this give me maximum happiness from 0 to level
  if(level==n){
    return 0;
  }
  // cache check
  if(dp[level][prev]!=-1){
    return dp[level][prev];
  }
  // transition 
  int ans=0;
   for(int i=1;i<=3;i++){
     if(i!=prev){
       ans=max(ans,arr[level][i]+rec(level+1,i));
     }
   }
  
  // here we have to save and return the answer
  return dp[level][prev]=ans;
  
}
void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
  }
  memset(dp,-1,sizeof(dp));
 cout<<rec(0,0)<<endl;
  
  
}
signed main(){
  solve();
}