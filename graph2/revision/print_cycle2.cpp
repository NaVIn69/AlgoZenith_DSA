#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis;
vector<int>parent;
bool cycle=false;
// here we store the parent of ith node
void dfs(int sc_node,int par){
    vis[sc_node]=1;
     parent[sc_node]=par;
     for(auto node:g[sc_node]){
        if(!vis[node]){

            dfs(node,sc_node);

        }else if(node!=par){
            // here we find out the cycle;
            // here we have to go in the reverse order
            if(!cycle){
            vector<int>path;
            int temp=sc_node;
            while(node!=temp ){
               
             path.push_back(temp);
             temp=parent[temp];
            }
            path.push_back(node);
            reverse(path.begin(),path.end());
            for(auto v:path){
                cout<<v<<" ";
            }
            cout<<endl;
            }
             
         cycle=true;

        }
     }
}
void solve(){
  cin>>n>>m;
  g.resize(n+1);
  vis.resize(n+1);
  parent.resize(n+1);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    // g[b].push_back(a);
  }
  dfs(1,-1);
  
  // here we have given sources node is 1
  
  

}
signed main(){
    solve();
}