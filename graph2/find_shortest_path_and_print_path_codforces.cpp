#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<pair<int,int>>>g;
vector<int>vis,dis,par;
void sssp(int sc){
    vis.assign(n+1,0);
    dis.assign(n+1,1e18);
    par.assign(n+1,-1);
    priority_queue<pair<int,int>>q;
    q.push(make_pair(0,sc));
    dis[sc]=0;
    while(!q.empty()){
          int node=q.top().second;
          q.pop();
          if(vis[node]) continue;
          vis[node]=1;
          for(auto v:g[node]){
             int neigh=v.first;
             int w=v.second;
              if(dis[neigh]>dis[node]+w){
                dis[neigh]=dis[node]+w;
                par[neigh]=node;
                q.push({-dis[neigh],neigh});
              }
          }
    }
}
void print_path(){
    vector<int>ans;
    int curr=n;
    while(curr!=-1){
        ans.push_back(curr);
        curr=par[curr];
    }
    //ans.push_back(1);
    reverse(ans.begin(),ans.end());
    for(auto v:ans){
        cout<<v<<" ";
    }
    cout<<endl;
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
    sssp(1);
  
    if(vis[n]!=0){
    print_path();
    }else{
        cout<<"-1"<<endl;
    }
    


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}