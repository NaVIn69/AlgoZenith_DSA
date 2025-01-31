//0 inf knapsack
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int w[3005];
int v[3005];
int n,W;
int dp[3005][3005];
int rec(int level,int left){
  // this gives me thw maximum value from level to n by choosing the left 
  if(level==n){
    return 0;
  }
  if(dp[level][left]!=-1){
    return dp[level][left];
  }
  // choice
  // val ki*vi-ki*ki
  //dont 
  int ans=rec(level+1,left);
  // take
  for(int num_times=1;num_times<=left/w[level];num_times++){
    int val=num_times*v[level]-num_times*num_times;
    ans=max(ans,val+rec(level+1,left-w[level]));
  }
  return dp[level][left]=ans;
}
void solve(){
  cin>>n>>W;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    w[i]=a;
    v[i]=b;
  }
  memset(dp,-1,sizeof(dp));
  cout<<rec(0,W)<<endl;
  
}
signed main(){
  solve();
}