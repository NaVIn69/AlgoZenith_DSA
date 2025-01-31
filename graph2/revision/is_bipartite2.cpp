#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis;
bool is_biaper=false;
void dfs(int sc_node,int col){
     vis[sc_node]=col;
     for(auto node:g[sc_node]){
        if(!vis[node]){
            dfs(node,3-col);
        }else if(col==vis[node]){
            is_biaper=true;
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
  // here we have given sources node is 1
  dfs(1,1);
  if(is_biaper){
    cout<<"Graph is biapertite"<<endl;
  }else{
    cout<<"graph is not bipertite"<<endl;
  }

  

}
signed main(){
    solve();
}