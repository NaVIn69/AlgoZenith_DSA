#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];
int dp[100100];
int rec(int level){
    // this fn return the mini cost to from level to n
    if(level>n){
        return 1e18;
    }
    // here base case is wrong
    if(level==n){
        return 0;
    }
    if(dp[level]!=-1){
        return dp[level];
    }
    int ans=1e18;
    for(int i=level+1;i<=min(n,level+k);i++){
        
        ans=min(ans,abs(arr[level]-arr[i])+rec(i));
        
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
 
}
signed main(){
    solve();
}