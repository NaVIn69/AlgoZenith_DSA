// here means when we are coloring the nodes graph then not two neighbouring nodes have same color
// odd cycle=non-bipartite
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis;
bool is_bipartite=true;
void dfs(int node,int color){
    vis[node]=color;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,3-color);
            //dfs(v,3^color);
        }else if(vis[v]==vis[node]){
               is_bipartite=false;
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
        g[b].push_back(a);
    }
    vis.resize(n+1,0);
    int color=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,color);
        }
    }
    cout<<is_bipartite<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<":"<<vis[i]<<endl;
    }

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
}