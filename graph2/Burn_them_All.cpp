#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<pair<int,int>>>g;
vector<pair<pair<int,int>,int>>edge;
vector<int>vis,dis;
void sssp(int sc){
    vis.assign(n+1,0);
    dis.assign(n+1,1e18);
    priority_queue<pair<int,int>>q;
    q.push({0,sc});
    dis[sc]=0;
    while (!q.empty())
    {
        auto node=q.top().second;
        q.pop();
        if(vis[node]) continue;
        vis[node]=1;
        for(auto v:g[node]){
            int neigh=v.first;
            int w=v.second;
            if(dis[neigh]>dis[node]+w){
                dis[neigh]=dis[node]+w;
                q.push({-dis[neigh],neigh});
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
        edge.push_back({{a,b},c});
    }
    int sc;
    cin>>sc;
    sssp(sc);
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" : "<<dis[i]<<endl;
    // }
    //in the distnace we know all the shortest distance from sources node 
    // after that for find the timing we are moving on the edges 
    int ans=-1e18;
    for(auto x:edge){
        int a=x.first.first;
        int b=x.first.second;
        int w=x.second;
        if(abs(dis[b]-dis[a])>=w){
            ans=(max(ans,(min(dis[a],dis[b])+w)*10));
        }else{
             ans=max(ans,(dis[a]+dis[b]+w)*5);
        }

    }
    cout<<ans<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}