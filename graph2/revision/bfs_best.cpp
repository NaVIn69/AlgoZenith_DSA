#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>dis,vis;
void bfs(int sc_node){
    vis.assign(n+1,0);
    dis.assign(n+1,1e9);
    queue<int>q;
    q.push(sc_node);
    dis[sc_node]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(auto v:g[x]){
            if(!vis[v]){
               dis[v]=dis[x]+1;
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
        cout<<i<<" "<<dis[i]<<" "<<endl;
    }



}
signed main(){
    solve();
}