#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define int long long
#define endl "\n"
vector<int>g[100100];
int dep[100100];
int par[100100];
void dfs(int node,int parent,int depth){
    dep[node]=depth;
    par[node]=parent;
    for(auto v:g[node]){
        if(v!=parent){
            dfs(v,node,depth+1);
        }
    }
}
void solve(){
    // n node 
    // (n-1) edge 
    // minimum cost (2e-path);
  int n;
  cin>>n;
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int u,v;
  cin>>u>>v;
  // here we have to find the distance between u and v
  dfs(u,0,0);
  cout<<dep[v]<<endl;

}
signed main(){
    solve();
}