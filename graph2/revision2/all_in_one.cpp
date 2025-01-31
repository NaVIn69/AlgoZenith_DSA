#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis;
vector<int>dis;
void dfs(int sc_node,int comp){
     vis[sc_node]=comp;
     for(auto node:g[sc_node]){
        if(!vis[node]){
            dfs(node,comp);
        }
     }
}
void bfs(int sc_node){
       vis.resize(n+1,0);
    dis.assign(n+1,1e9);
    dis[sc_node]=0;
    queue<int>q;
    q.push(sc_node);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(vis[node]) continue;
        vis[node]=1;
        for(auto v:g[node]){
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
    vis.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


}
signed main(){

}