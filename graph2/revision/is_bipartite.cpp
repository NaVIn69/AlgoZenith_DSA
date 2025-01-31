#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis;
bool is_bipartite=false;
// here are trying to color all the nodes with 2 color
void dfs(int node,int color){
    vis[node]=color;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,3-color);
            // here both node have the same color
        }else if(vis[v]==vis[node]){
           is_bipartite=true;
        }
    }

}
void solve(){
  cin>>n>>m;
  g.resize(n+1);
  vis.resize(n+1);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1,1);
  if(is_bipartite){
  cout<<"odd cycle and graph is bipartite"<<endl;
  }else{
    cout<<"graph is not bipartite"<<endl;
  }

}
signed main(){
    solve();
}