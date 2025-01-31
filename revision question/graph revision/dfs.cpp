#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we have to find the connected component of graph
int n,m;
vector<vector<int>>g;
vector<vector<int>>comp;
vector<int>vis;
 void dfs(int sc_node,int cmp){ 
    comp[vis]
    vis[sc_node]=cmp;
    for(auto node:g[sc_node]){
        if(!vis[node]){
            dfs(node,cmp);
        }
    }
 }
void solve(){
    cin>>n>>m;
  g.resize(n+1);
  comp.resize(n+1);
  vis.resize(n+1);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int cmp=1;
 for(int i=1;i<=n;i++){
     if(!vis[i]){
       
        dfs(i,cmp);
        cmp++;
     }
    
     
 }
 for(int i=1;i<=n;i++){
    cout<<vis[i]<<" ";
 }



}
signed main(){
    solve();
}