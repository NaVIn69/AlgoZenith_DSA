#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,w;
int weight[10001];
int value[10001];
// here we take dp of level and weight
int dp[101][100100];

int rec(int level,int wt){
    // purning
   

    // basecase
    if(level==n) return 0;

    // cache check
    if(dp[level][wt]!=-1){
        return dp[level][wt];
    }

    // transition  compute
    // dont take
    int ans=rec(level+1,wt);

   // take
   if(wt+weight[level]<=w){
     ans=max(ans,value[level]+rec(level+1,wt+weight[level]));
   }
    // save and return
    return dp[level][wt]=ans;

   
}
void solve(){
  cin>>n>>w;
  for(int i=0;i<n;i++){
    cin>>weight[i]>>value[i];
  }
  memset(dp,-1,sizeof(dp));
   cout<<rec(0,0)<<endl;

}
signed main(){
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}