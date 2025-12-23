#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>dis;
vector<int>vis;
void bfs(int sc_node){
    vis.assign(n+1,0);
    dis.assign(n+1,1e18);
    dis[sc_node]=0;
    queue<int>q;
    q.push(sc_node);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(vis[node])continue;
        vis[node]=1;
        for(auto v:g[node]){
            // relax that edge
            if(!vis[v]&&dis[v]>dis[node]+1){
                dis[v]=dis[node]+1;
                q.push(v);
            }
        }
    }
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
    bfs(1);
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }


}
signed main(){
    solve();
}