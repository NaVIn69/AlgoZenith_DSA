#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis;
vector<int>parent;
bool is_cycle=false;
// here we have tofind the cycle in the directed graph
void dfs(int node,int par){
    vis[node]=2;
    parent[node]=par;
    for(auto v:g[node]){
        if(vis[v]==1){
            // we have to traverse the all the nodes of 
            dfs(v,node);
        }else if(vis[v]==2){
            // here we find the backedge
            is_cycle=true;

        }
    }
    vis[node]=3;
   // here we have been traverse all the child of the node 
}
void solve(){
   cin>>n>>m;
   g.resize(n+1);
   for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
   }
   vis.assign(n+1,0);
   for(int i=1;i<=n;i++){
    if(!vis[i]){
        dfs(i,0);
    }
   }
   if(is_cycle){
    cout<<"Yes"<<endl;
   }else{
    cout<<"No"<<endl;
   }
   is_cycle=false;
}

signed main(){
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}