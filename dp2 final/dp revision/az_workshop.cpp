#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we have given x time and k slots , we have find the maximum skill and also print the which question we have been selected
int n,x,k;
int skill[1001];
int t[1001];
// here we do the caching like 
int dp[100][1001][100];

int rec(int level,int rem_time,int rem_slots){
    // this gives me maximum value of skill , from (level to n-1 ) at which we have rem_time and rem_slots
    if(level==n){
        // we have travelled all the question 
        return 0;
    }
  // cache check
  if(dp[level][rem_time][rem_slots]!=-1){
    return dp[level][rem_time][rem_slots];
  }

    // choice 
    int ans=0;
    // this ans store the maximum skill from (level to n-1) and we have rem_time and rem_slots . 
    // take 
    if(rem_slots!=0&&rem_time>t[level]){
      ans=max(ans,skill[level]+rec(level+1,rem_time-t[level],rem_slots-1));
    }
    // dont take
    ans=max(ans,rec(level+1,rem_time,rem_slots));
    return dp[level][rem_time][rem_slots]=ans;
}

void solve(){
    cin>>n>>x>>k;
    for(int i=0;i<n;i++){
        cin>>skill[i];
    }
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,x,k)<<endl;


}
signed main(){
    solve();
}