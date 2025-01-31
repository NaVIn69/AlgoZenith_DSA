#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<pair<int,int>>>g;
vector<int>dis,vis,par;
void dijkstra(int sc_node){
    dis.assign(n+1,1e9);
    vis.assign(n+1,0);
    priority_queue<pair<int,int>>pq;
    pq.push({-0,sc_node});
    dis[sc_node]=0;
    while(!pq.empty()){
        pair<int,int>node=pq.top();
        pq.pop();
        int n=node.second;
        int curr_dist=-node.first;
        if(vis[n]) continue;
        vis[n]=1;
        for(auto v:g[n]){
           if(!vis[v.first]&&dis[v.first]>curr_dist+v.second){
               dis[v.first]=dis[n]+v.second;
               pq.push({-dis[v.first],v.first});
           }
        }

    }
}
void solve(){
 cin>>n>>m;
 g.resize(n+1);
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
 }
 dijkstra(1);
 for(int i=0;i<n;i++){
    cout<<dis[n]<<" ";
 }
 cout<<endl;



}
signed main(){
    solve();
}