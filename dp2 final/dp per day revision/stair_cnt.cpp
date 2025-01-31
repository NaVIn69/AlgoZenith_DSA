#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int dp[100100];
int rec(int level){
    // this recursive tells me about the number of ways to go from level to n stair
    if(level==n){
        return 1;
    }
    // cache check
    if(dp[level]!=-1){
        return dp[level];
    }
    // transition
    // choice
    int ans=0;
    for(int step=1;step<=3;step++){
        // we go through all th choice of that level
        if(level+step<=n){
          ans+=rec(level+step);
        }
    }
     return dp[level]=ans;

}
void solve(){
 cin>>n;
 memset(dp,-1,sizeof(dp));
 cout<<rec(1)<<endl;

}
signed main(){
    solve();
}