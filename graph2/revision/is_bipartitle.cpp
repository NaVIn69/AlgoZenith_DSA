#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis;

bool check=false;
void dfs(int sc_node,int color){
    vis[sc_node]=color;
  
    for(auto node:g[sc_node]){
         if(!vis[node]){
            dfs(node,3-color);
         }else if(vis[node]==vis[sc_node]){
               check=true;
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
   
    // printing the graph to visual stuff
    for(int i=0;i<n;i++){
        cout<<"node"<<" "<<i<<endl;
        for(int j=0;j<g[i].size();j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"n"<<endl;
    vis.resize(n+1);
    dfs(1,1);
    for(int i=0;i<vis.size();i++){

        cout<<i<<" "<<vis[i]<<endl;
    }
     if(check){
        cout<<"graph is bipartite"<<endl;
    }


    

}
signed main(){
    solve();
}