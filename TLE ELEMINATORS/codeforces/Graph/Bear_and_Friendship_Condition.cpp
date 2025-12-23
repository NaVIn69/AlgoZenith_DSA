#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,m;
vector<vector<int>>g;
vector<int>dis,vis;

void bfs(int sc_node){
     dis[sc_node]=0;
     queue<int>q;
     q.push(sc_node);
     while(!q.empty()){
         int node=q.front();
         q.pop();
         if(vis[node])continue;
         vis[node]=1;
         for(auto v:g[node]){
              if(!vis[v]&&dis[v]>dis[node]+1){
                // relax that edge 
                 dis[v]=dis[node]+1;
                 q.push(v);
              }
         }
     }
}

void dfs(int node,int comp_no,int&edge){
     vis[node]=comp_no;
     for(int v:g[node]){
        edge++;
         if(!vis[v]){
          
            dfs(v,comp_no,edge);
         }
     }
}
void solve(){
 cin>>n>>m;
 g.resize(n+1);
 vis.assign(n+1,0);
 dis.assign(n+1,1e18);
  for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
  }
 int comp_no=0;
 map<int,pair<int,int>>mpp;// cc-> edge , nodes 
   for(int i=1;i<=n;i++){
       if(!vis[i]&&g[i].size()!=0){
        comp_no++;
        int edge=0;
          dfs(i,comp_no,edge);
          mpp[comp_no]={edge,0};
       }
   }
   for(int i=1;i<=n;i++){
    if(vis[i]){
      mpp[vis[i]].second++;
    }
   }
//    for(auto x:mpp){
//       cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
//    }
   for(auto x:mpp){
         int ed=x.second.first/2;
         int cnt=x.second.second;
         int tot=((cnt*(cnt-1))/2);
         if(ed!=tot){
            cout<<"NO"<<endl;
            return;
         }
   }
cout<<"YES"<<endl;


    // for(int i=1;i<=n;i++){
    //      if(!vis[i]){
    //          bfs(i);
    //      }
    // } 
    // // here we connected compononent distance must be less than <=1

    // for(int i=1;i<=n;i++){
    //     if(dis[i]>1){
    //         cout<<"NO"<<endl;
    //         return ;
    //     }
    // }
    // cout<<"YES"<<endl; // each node are conncted to each other 

}
signed main(){
    solve();
}