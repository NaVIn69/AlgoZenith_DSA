
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
int mod=1e9+7;
vector<vector<int>>g,parent;
vector<int>vis,indeg,outdeg,topo;
 void dfs(int node){
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
    topo.push_back(node);
 }
 int dp[100100];
 int rec(int node){ // give me total number of path starting from node and end to last node
    if(node==n){
        dp[node]=1;
       return dp[node];
     }
     if(dp[node]!=-1) return dp[node];
     int ans=0;
     for(auto v:g[node]){
          ans=(ans%mod+rec(v)%mod)%mod;
     }
     dp[node]=ans;
     return dp[node];

 }
void solve(){
  cin>>n>>m;
  g.resize(n+1);
  vis.assign(n+1,0);
  indeg.assign(n+1,0);
  outdeg.assign(n+1,0);
  parent.resize(n+1);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
   
    
  }
  memset(dp,-1,sizeof(dp));
//    for(int i=1;i<=n;i++){
//       if(!vis[i]){
//         dfs(i);
//       }
//    }
   cout<<rec(1)<<endl;
   
    
  



}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}