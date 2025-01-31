#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n,k;
int dp[100100];
int fib(int n){
    //base case
    if(n==0) return 1;
    if(n<k) return 0;

    //cache check
    if(dp[n]!=-1){
        return dp[n];
    }

    //transition
    dp[n]=0;
    for(int i=1;i<=k;i++){
        dp[n]+=fib(n-i );
    }


    //save and return
    return dp[n];
}
void solve(){
  cin>>n>>k;
  memset(dp,-1,sizeof(dp));
  cout<<fib(n)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}