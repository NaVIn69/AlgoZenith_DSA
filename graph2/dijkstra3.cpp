#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using ii= pair<int,int>;
int n,m;
vector<pair<int,int>>g[100100];
int dis[100100];
int vis[100100];

void sssp(int sc){
   for(int i=1;i<=n;i++){
    dis[i]=1e18;
    vis[i]=0;
   }
   dis[sc]=0;
   priority_queue<pair<int,int>>pq;
   pq.push({0,sc});
   while(!pq.empty()){
     ii node=pq.top();
     pq.pop();
     if(vis[node.second]) continue;;
     vis[node.second]=1;
     for(auto v:g[node.second]){
          int neigh=v.first;
          int wt=v.second;
          if(dis[neigh]>dis[node.second]+wt){
            dis[neigh]=dis[node.second]+wt;
            // here we inserting the node with smallest edge 
            pq.push({-dis[node.second],neigh});
          }
     }

   }


}

void solve(){
 cin>>n>>m;
 for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    g[a].push_back({b,c});
    g[b].push_back({a,c});
 }
 int sc;
 cin>>sc;
 sssp(sc);
 for(int i=1;i<=n;i++){
    cout<<dis[i]<<" ";
 }
 cout<<endl;


}
signed main(){
    solve();
}