#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we have to find the total number ways to move from 1 to n where we have choice like 1 ,2 ,3 steps
int dp[100100];

int n;
int rec(int level){
    // this fn give me total number of ways to reach at n using thier choice
    // purning
    if(level>n) return 0; 

    // base case
    if(level==n){
        // we reached at nth stairs then one possible ways we find out
        return 1;
    }

    if(dp[level]!=-1){
        return dp[level];
    }

    // choice 
    int ans=0;
    for(int j=1;j<=3;j++){
         ans+=rec(j+level);
    }
    return dp[level]=ans;
}
void solve(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<rec(1)<<endl;
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }

}
signed main(){
    solve();
}
