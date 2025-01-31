#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
vector<int>dp;
int fib(int n){
    //base case
    if(n==0) return 0;
    if(n==1) return 1;
 
    //check
    if(dp[n]!=-1) return dp[n];

   // transition
   dp[n]=fib(n-1)+fib(n-2);

   return dp[n];
}
void solve(){
    int n;
    cin>>n;
    dp.resize(n+1,-1);
   int ans=fib(n);
   cout<<dp[n]<<endl;



}
signed main(){
    solve();
}