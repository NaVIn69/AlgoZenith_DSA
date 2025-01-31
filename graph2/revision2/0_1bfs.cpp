#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<pair<int,int>>>g;
vector<int>vis,dis;

void bfs01(int sc_node){
   vis.assign(n+1,0);
   dis.assign(n+1,1e9);
  
  deque<int>dq;
  dq.push_back(sc_node);
  dis[sc_node]=0;
  while(!dq.empty()){
    int node=dq.front();
    dq.pop_front();
    if(vis[node])continue;
    vis[node]=1;
    for(auto v:g[node]){
        int wt=v.second;
        if(dis[v.first]>dis[node]+wt){
            dis[v.first]=dis[node]+wt;
            if(wt==0){
                dq.push_front(v.first);
            }else{
                dq.push_back(v.first);
            }
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

}