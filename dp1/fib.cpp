#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int>dp;
int n;
int fib(int n){
    // base case
    if(n<=1) return n;
    // memoization /caching
    if(dp[n]!=-1){
        //already computed
        return dp[n];
    }
    //transition
    dp[n]=fib(n-1)+fib(n-2);
    return dp[n];

}
void solve(){
    cin>>n;
    dp.resize(n+1,-1);
    cout<< fib(n)<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}