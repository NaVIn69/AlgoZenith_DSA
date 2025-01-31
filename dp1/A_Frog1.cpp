#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int h[100100];
vector<int>dp;
int rec(int level){
    // base case
    // 0 se 0 pe janne ka cost 0
    if(level==0) return 0;

      // cache check
     if(dp[level]!=-1){
        return dp[level];
     }

     //transition
    int left=rec(level-1)+abs(h[level]-h[level-1]);
    int right=1e9;
    // here level is greater than one because level -2 is doing

    if(level>1){
         right=rec(level-2)+abs(h[level]-h[level-2]);
    }
    return dp[level]=min(left,right);
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    dp.resize(n+1,-1);
   int ans = rec(n-1);
     cout<<dp[n-1]<<endl;





}
signed main(){
    solve();
}