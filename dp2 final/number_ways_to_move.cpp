#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int dp[100100];
// here dp[i] tells me about the number of ways to move from i to n
int rec(int level){
    // this function return me the number of ways to move from level to n-1;
    

    //purning
    if(level>n){
        return 0;
    }

    //base case
    if(level==n){
        return 1;
    }

    //cacheing
    if(dp[level]!=-1){
        return dp[level];
    }

    // choice
    // we have three choice to move from level .. 1 step,, 2 step,, 3 step
    int ans=0;
    for(int step=1;step<=3;step++){
         // check
         if(step+level<=n){
          ans+=rec(level+step);
         }
    }
    
    // store
     dp[level]=ans;
    // return 
    return ans;
}
void solve(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    int ans=rec(1);
  cout<<dp[1]<<endl;


}
signed main(){
    solve();
}