// here we use the deque 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
// here have the graph with weight of edge
vector<vector<pair<int,int>>>g;
vector<int>dis,vis;

void sssp(int sc_node){
   vis.assign(n+1,0);
   dis.assign(n+1,1e9);
   deque<int>dq;
   dq.push_back(sc_node);
   dis[sc_node]=0;
   while(!dq.empty()){
     int node=dq.front();
     dq.pop_front();
     if(vis[node]) continue;
     vis[node]=1;
     for(auto v:g[node]){
        // traversing all the neighbours of that node
        int neigh=v.first;
        int weigh=v.second;
        // here we are relaxing the edge of graph
        if(dis[neigh]>dis[node]+weigh){
            dis[neigh]=dis[node]+weigh;
        }
        if(weigh==0){
            dq.push_front(neigh);
        }else{
            dq.push_back(neigh);
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
    g[b].push_back({a,c});
  }

}
signed main(){
    solve();
}