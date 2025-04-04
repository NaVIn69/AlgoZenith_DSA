#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we have to find the minimum cost to reach at node n
// here we have to find the total number of path(shortest path) reach at node n 
// count the path in which we have crossed minimum number of node to reach at destination with minimum cost 
// count the path in which we have been crossed maximum number of node to reach at the destination with minimum cost
// state of node ={minimum price , number of path , count total number of path in which min number of nodes crossed to reach at that node from source ,
// count total number of path in which we have been crossed the maximum number of nodes with minimum cost  }
int mod=1e9+7;
int n,m;
vector<vector<pair<int,int>>>g;
vector<int>dis,path,min_node_crossed_count_path,maxi_node_crossed_count_path;
vector<int>vis;
void sssp(int sc){
    dis.assign(n+1,1e18);
    path.assign(n+1,0);
    vis.assign(n+1,0);
    min_node_crossed_count_path.assign(n+1,0);
    maxi_node_crossed_count_path.assign(n+1,0);
    dis[sc]=0;
    path[sc]=1;

    // min_node_crossed_count_path[sc]=1;
    // maxi_node_crossed_count_path[sc]=1;
    priority_queue<pair<int,int>>pq;
    pq.push({-0,sc});
    while(!pq.empty()){
        int node=pq.top().second;
        int curr=-pq.top().first;
        pq.pop();
        if(vis[node])continue;
        vis[node]=1;
        for(auto v:g[node]){
            int neigh=v.first;
            int wt=v.second;

            if(dis[neigh]>dis[node]+wt){
               // here we are relaxing that edge node -- wt --> neigh
               path[neigh]=path[node]; // 
               dis[neigh]=dis[node]+wt;
               min_node_crossed_count_path[neigh]=min_node_crossed_count_path[node]+1;
               maxi_node_crossed_count_path[neigh]=maxi_node_crossed_count_path[node]+1;
               pq.push({-dis[neigh],neigh});
            }else if(dis[neigh]==dis[node]+wt){
                // here we have to count; we have been relax previously 
                path[neigh]=(path[neigh]%mod+path[node]%mod)%mod;
                min_node_crossed_count_path[neigh]=min({min_node_crossed_count_path[neigh],min_node_crossed_count_path[node]+1});
                maxi_node_crossed_count_path[neigh]=max({maxi_node_crossed_count_path[neigh],maxi_node_crossed_count_path[node]+1});               
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
    }
    sssp(1);
    // for(int i=1;i<=n;i++){
    //     cout<<dis[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<path[i]<<" "<<min_node_crossed_count_path[i]<<" "<<maxi_node_crossed_count_path[i]<<endl;
    // }

    if(dis[n]==1e18){
        cout<<"-1"<<endl;
        return ;
    }
    cout<<dis[n]<<" "<<path[n]<<" "<<min_node_crossed_count_path[n]<<" "<<maxi_node_crossed_count_path[n]<<endl;


}
signed main(){
    solve();
}