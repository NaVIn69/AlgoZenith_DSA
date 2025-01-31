#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis,dis;
void bfs(int sc_node){
    vis.resize(n+1);
    dis.resize(n+1);
    queue<int>q;
    q.push(sc_node);
    vis[sc_node]=1;
    dis[sc_node]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop(); 
        // traversing all the neighbours of that node
        for(auto v:g[node]){
            if(!vis[v]){
                vis[v]=1;
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
        cout<<i<<" "<<dis[i]<<endl;
    }
    cout<<endl;


}
signed main(){
    solve();
}