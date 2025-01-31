#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int dp[100100];
int rec(int level){
    // here this will return the number of ways to go from level to n
    if(level==n){
        // there is one way to go
        return 1;
    }
    // cache check
    if(dp[level]!=-1){
        return dp[level];
    }
    // choice
    int ans=0;
    for(int ch=1;ch<=3;ch++){
        if(level+ch<=n){
           ans+=rec(level+ch);
        }
    }
    return dp[level]= ans;
}
void solve(){
cin>>n;
memset(dp,-1,sizeof(dp));
int ans=rec(1);
cout<<ans<<endl;


}
signed main(){
    solve();
}