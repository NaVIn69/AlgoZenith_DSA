#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis;
vector<int>dis;
vector<int>num_path;
void bfs(int st_node){
    vis[st_node]=1;
    dis[st_node]=0;
    num_path[st_node]=1;
    queue<int>q;
    q.push(st_node);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto v:g[node]){
            if(!vis[v]){
                vis[v]=1;
                dis[v]=dis[node]+1;
                num_path[v]=num_path[node];
                q.push(v);
            }else if(dis[v]==dis[node]+1){
                num_path[v]+=num_path[node];
            }
        }

    }
}
// }
// void bfs(int sc_node){
//      vis.assign(n+1,0);
//      dis.assign(n+1,1e9);
//      queue<int>q;
//      dis[sc_node]=0;
//      q.push(sc_node);
//      while(!q.empty()){
//         int x=q.front();
//         q.pop();
//         if(vis[x])continue;
//         vis[x]=1;
//         for(auto v:g[x]){
//             if(dis[v]>dis[x]+1){
//                 dis[v]=dis[x]+1;
//                 q.push(v);
//             }
//         }
//      }
// }
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        // g[b].push_back(a);
    }
    vis.resize(n+1,0);
    dis.resize(n+1,1e9);
    //here we are trying to calculate the number of shortest path from sources node to any node
    num_path.assign(n+1,0);
    bfs(1);
    cout<<num_path[n]<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<i<<":"<<vis[1]<<","<<dis[i]<<endl;
    // }
    



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