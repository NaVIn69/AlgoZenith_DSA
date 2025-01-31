#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,x,k;
int t[100];
int skill[100];
int dp[100][100][100];
int rec(int level,int time_left,int slot_left){
    // this will return the maximum skill from level to n
    if(level==n){
         return 0;
    }
    if(dp[level][time_left][slot_left]!=-1){
        return dp[level][time_left][slot_left];
    }
    /// choice
    // take
    int ans=0;
    if(time_left>=t[level]&&slot_left>0){
        ans=rec(level+1,time_left-t[level],slot_left-1);
    }
    // dont take
    ans=max(ans,rec(level+1,time_left,slot_left));
    return ans;
}

void solve(){
   cin>>n>>x>>k;
   for(int i=0;i<n;i++){
    cin>>t[i];
   }
   for(int i=0;i<n;i++){
    cin>>skill[i];
   }
   memset(dp,-1,sizeof(dp));
   cout<<rec(0,x,k)<<endl;
}
signed main(){
    solve();
}