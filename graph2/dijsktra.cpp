#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<pair<int,int>>>g;
vector<int>vis,dis;
vector<int>path;
void sssp(int sc){
    vis.assign(n+1,0);
    dis.assign(n+1,1e18);
    path.assign(n+1,0);
    priority_queue<pair<int,int>>q;
    q.push(make_pair(0,sc));
    path[sc]=1;

    dis[sc]=0;
    while(!q.empty()){
          int node=q.top().second;
          int curr=-q.top().first;
          q.pop();
          if(vis[node]) continue;
          vis[node]=1;
          for(auto v:g[node]){
             int neigh=v.first;
             int w=v.second;
              if(dis[neigh]>dis[node]+w){
                dis[neigh]=dis[node]+w;
                q.push({-dis[neigh],neigh});
                path[neigh]=path[node];
              }else if(dis[neigh]==dis[node]+w){
                path[neigh]=path[neigh]+path[node];
              }
          }
    }
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    //    g[b].push_back({a,c});
    }
    int x=1;
    sssp(x);
   for(int i=1;i<=n;i++){
    cout<<dis[i]<<" ";
   }
   cout<<endl;
   for(int i=1;i<=n;i++){
    cout<<path[i]<<" ";
   }
   cout<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}