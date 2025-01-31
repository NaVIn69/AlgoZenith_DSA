#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n;
int t[1001]; // here time is stored for every problem
int s[1001]; // skill -> from every problem how much skill i can get it
int taken[1001]; // it tells me about which problem  is taken or not 
int x,k;   // given x time and k slot of problem 

// find the maximum skill i can get it from  taking x time and k problem. 
// form 1
  int dp[101][101][101];

  int rec(int level,int time_taken,int item_taken){
     // maximum skill i can make from [level......n-1]
    //level ->current pos
   // purning

   // base case
    if(level==n) return 0;
   // cache check
    if(dp[level][time_taken][item_taken]!=-1){
        return dp[level][time_taken][item_taken];
    }

   // transition
   // dont take       us level wale element ko nhi lena hai
    int ans=rec(level+1,time_taken,item_taken);

    // take
    if(time_taken+t[level] <=x && item_taken+1<=k){
        ans=max(ans,s[level]+rec(level+1,time_taken+t[level],item_taken+1));
    }

   // save and return 
   return dp[level][time_taken][item_taken]=ans;
  }

void solve(){
    cin>>n>>x>>k;
    for(int i=0;i<n;i++){
        cin>>t[i]>>s[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,x,k)<<endl;


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
