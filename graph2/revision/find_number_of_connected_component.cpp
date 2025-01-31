#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis;
vector<vector<int>>all_comp;
// here index will tell me about the component number , and 
// in dfs we do the color twiking
void dfs(int node,int num_comp){
  vis[node]=num_comp;
  for(auto v:g[node]){
    if(vis[v]==0){
        dfs(v,num_comp);
    }
  }
}
void solve(){
  cin>>n>>m;
  g.resize(n+1);
  vis.resize(n+1);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  // here we hjave to find the number of connected componnent
  // and here we also want to fins the query of node which node belongs which connected component
  // also find the 
  int num_component=0;
  for(int i=1;i<=n;i++){
     if(vis[i]==0){
      num_component++;
     dfs(i,num_component);
     }
  }
 vector<vector<int>>all_comp;
 all_comp.resize(num_component+1);
 for(int i=1;i<=n;i++){
    all_comp[vis[i]].push_back(i);
 }
 // here we are printing the all component with their size and their element

 for(int i=1;i<all_comp.size();i++){
    cout<<"component number "<<" "<<i<<endl;
    for(int j=0;j<all_comp[i].size();j++){
        cout<<all_comp[i][j]<<" ";
    }
    cout<<endl;
 }

}
signed main(){
    solve();
}