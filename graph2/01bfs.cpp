//here we have given a weighted graph
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<pair<int,int>>>g;
vector<int>vis,dis;
void bfs01(int sc){
    vis.assign(n+1,0);
    dis.assign(n+1,1e9);
    deque<int>q;
    dis[sc]=0;
    q.push_back(sc);
    while(!q.empty()){
        int x=q.front();
        q.pop_front();
        if(vis[x]) continue;
        vis[x]=1;
        for(auto v:g[x]){
            int neigh=v.first;
            int weigh=v.second;
            if(dis[neigh]>dis[x]+weigh){
                dis[neigh]=dis[x]+weigh;
                if(weigh==0){
                    q.push_front(neigh);
                }else{
                    q.push_back(neigh);
                }
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
    g[a].push_back({b,0});
    g[b].push_back({a,1});
  }
  int sc=0;
  cin>>sc;
  bfs01(sc);
  for(int i=1;i<=n;i++){
    cout<<i<<" : "<<dis[i]<<endl;
  }
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}