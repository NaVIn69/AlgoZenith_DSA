#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis;
bool is_cycle=false;
void dfs(int sc_node,int par){
  
     vis[sc_node]=par;
     for(auto node:g[sc_node]){
        if(!vis[node]){
            dfs(node,sc_node);
        }else if(node!=par){
           is_cycle=true;
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
    // g[b].push_back(a);
  }
  // here we have given sources node is 1
  dfs(1,-1);
  for(int i=1;i<=n;i++){
    cout<<vis[i]<<" ";
  }
  if(is_cycle){
    cout<<"cycle is present"<<endl;
  }

}
signed main(){
    solve();
}