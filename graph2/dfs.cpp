#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//undirected graph
int mod=1e9+7;
int n,m;
vector<vector<int>>g;
vector<int>vis;
void dfs(int node){
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
void solve(){
   cin>>n>>m;
   g.resize(n+1);
   for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    //undirected
    g[b].push_back(a);
   }
   vis.resize(n+1,0);
   dfs(1);
   // here we have to see how 
   // my graph is look like
//    for(int i=0;i<g.size();i++){
//     cout<<i<<" "<<"child"<<" ";
//         for(int j=0;j<g[i].size();j++){
//             cout<<g[i][j]<<" ";
//         }
//         cout<<endl;
//    }
   for(int i=1;i<=n;i++){
    cout<<i<<" "<<vis[i]<<endl;
   }
}
signed main(){
    solve();
}