#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,a,b;
int arr[200200];
vector<vector<pair<int,int>>>g;
map<int,vector<int>>mpp;
vector<int>dis,vis;
// here g is directed graph
void dijkstra(int sc_node){
    int l=n+mpp.size()+1;
    dis.assign(l+1,1e18);
    vis.assign(l+1,0);
    priority_queue<pair<int,int>>pq;
    dis[sc_node]=0;
    pq.push({0,sc_node});
    while(!pq.empty()){
        pair<int,int> x=pq.top();
        int node=x.second;
        int dist=-x.first;

        pq.pop();
        if(vis[node])continue;
        vis[node]=1;
        for(auto v:g[node]){
            int neigh=v.first;
            int wt=v.second;
            if(dis[neigh]>dis[node]+wt){
                dis[neigh]=dis[node]+wt;
                pq.push({-dis[neigh],neigh});
            }
        }
    }

}
void solve(){
    cin>>n>>a>>b;
  
    // for wwe store for every value where it is present in the graph
    // (1....n) is my node of the graph
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        mpp[x].push_back(i);
    }
    // we gennearte the graph of size n+distnict_number
    // we generate the node and we connect the same number with a specific node
    g.resize(n+mpp.size()+1);
    // near by element is connect 
    for(int i=1;i<=n;i++){
        g[i].push_back({i+1,b});
        g[i+1].push_back({i,b});
    }
    // here n node connect to each other
    int node=n+1;
    for(auto &v:mpp){
        for(auto u:v.second){
            g[node].push_back({u,b});
            g[u].push_back({node,0});
        }
    }
    int src;
    cin>>src;
    dijkstra(src);
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;




}
signed main(){
    solve();
}
      