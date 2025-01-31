/*
Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces.

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int prices[1005];
int dp[1005][1005];
int rec(int l,int r){
  



}
// here we find how much we have to cut //
// how much length of cut is optimal;
void solve(){
    cin>>n;
    prices[0]=0;
    for(int i=1;i<=n;i++){
        cin>>prices[i];
    }
    memset(dp,-1,sizeof(dp));
    
  

}
signed main(){
    solve();
}