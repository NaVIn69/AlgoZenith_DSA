#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int dp[100];
int rec(int level){
    // this fn return the total number of ways (0....level) 
    // level==0 means we have find the one orination
 if(level==0) return 1;
 if(level==1) return 0;
 if(dp[level]!=-1) return dp[level];
 int ans=2*rec(level-2);
 return  dp[level]=ans;
}
void solve(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<rec(n)<<endl;


}
signed main(){
    solve();
}