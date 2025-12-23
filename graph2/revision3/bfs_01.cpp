#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<pair<int,int>>g;
vector<int>vis,dis;
void bfs01(int sc_node){
     dis.assign(n+1,1e9);
     vis.assign(n+1,0);
     deque<int>dq;
     dq.push_back(sc_node);
     dis[sc_node]=0;
     while(!dq.empty()){
        int node=dq.front();
        dq.pop_front();
        if(vis[node])continue;
        vis[node]=1;
        for(auto v:g[node]){
            int neigh=v.first;
            int wt=v.second;
            if(!vis[neigh]&&dis[neigh]>dis[node]+wt){
                dis[neigh]=dis[node]+wt;
                if(wt==0){
                    dq.push_front(neigh);
                }else{
                    dq.push_back(neigh);
                }
            }
        }
     }
     for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
     }
     cout<<endl;
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }



}
signed main(){
    solve();
}