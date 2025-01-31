// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl "\n"
// int n,m;
// vector<vector<pair<int,int>>>g;
// vector<int>dis;
// vector<int>vis;
// void bfs(int sc_node){
//     dis.assign(n+1,1e9);
//     vis.assign(n+1,0);
//     deque<int>q;
//     q.push_back(sc_node);
//     dis[sc_node]=0;
//     while(!q.empty()){
//         int node=q.front();
//         q.pop_front();
//         if(vis[node])continue;
//         vis[node]=1;
//         for(auto v:g[node]){
//             int w=v.second;
//             if(dis[v.first]>dis[node]+w){
//                 dis[v.first]=dis[node]+w;
//                 if(w==0){
//                     q.push_front(v.first);
//                 }else{
//                     q.push_back(v.first);
//                 }
//             }
//         }
//     }
// }
// void solve(){
//     cin>>n>>m;
// //    g.assign(n+1,vector<int>(m+1));
//   g.resize(n+1);
//    for(int i=0;i<m;i++){
//     int a,b;
//     cin>>a>>b;
//     g[a].push_back({b,0});
//     // if(a!=b){
//     g[b].push_back({a,1});
//     //}
//    }
//    bfs(1);
//    if(dis[n]==1e9){
//     cout<<"-1"<<endl;
//    }else{
//     cout<<dis[n]<<endl;
//    }
// // }
// signed main(){
//     int t=1;
//     cin>>t;
//     while(t--){
//     solve();
//     }
// }
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
 bfs01(1);
 if(dis[n]==1e9){
    cout<<"-1"<<endl;
 }else{
    cout<<dis[n]<<endl;
 }
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}