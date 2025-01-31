#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,x,k;
int skill[1001];
int tim[1001];
int dp[101][1001][101];
int rec(int level,int time_left,int item_left){
    // this function gives me the total maximum value we can obtain from level to n where we have time_left and item_left
    if(time_left<0||item_left<0){
        // invalid case
        return -1e9;
    }
     // base case
    if(level==n){
        return 0;
    }
    // cache check
    if(dp[level][time_left][item_left]!=-1){
        return dp[level][time_left][item_left];
    }
    
    // transition
    // choice
    // dont take
    int ans=rec(level+1,time_left,item_left);
    //take
    if(tim[level]<=time_left){
      ans=max(ans,skill[level]+rec(level+1,time_left-tim[level],item_left-1));
    }

    dp[level][time_left][item_left]=ans;
    return ans;


}
void solve(){
cin>>n>>x>>k;
    for(int i=0;i<n;i++){
        cin>>skill[i];
    }
    for(int i=0;i<n;i++){
        cin>>tim[i];
    }
    memset(dp,-1,sizeof(dp)); 
    cout<<rec(0,x,k)<<endl;
}
signed main(){
    solve();
}