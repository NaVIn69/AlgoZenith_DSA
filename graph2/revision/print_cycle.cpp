#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis;
vector<int>parent;
bool is__cycle=false;
void dfs(int node,int par){
      vis[node]=1;
      parent[node]=par;
      for(auto v:g[node]){
           if(!vis[v]){
              dfs(v,node);
           }else if(v!=par){
            //   is__cycle=true;
              if(!is__cycle){
                vector<int>cycle;
                int temp=node;
                while(temp!=v){
                    cycle.push_back(temp);
                    temp=parent[temp];
                }
               cycle.push_back(v);
               reverse(cycle.begin(),cycle.end());
               for(auto v:cycle){
                   cout<<v<<" ";
              }
              cout<<endl;
              is__cycle=true;
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
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //   for(int i=0;i<n;i++){
    //     cout<<"node"<<" "<<i<<endl;
    //     for(int j=0;j<g[i].size();j++){
    //         cout<<g[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    parent.resize(n+1);
    vis.resize(n+1);
    dfs(1,0);
    for(int i=0;i<parent.size();i++){
        cout<<i<<" "<<parent[i]<<endl;
    }
    cout<<endl;



}
signed main(){
    solve();
}