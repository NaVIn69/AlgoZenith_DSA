#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
int parent[100100];
// int dep[100100];
vector<int>vis;
bool is_cycle=false;
// cycle is not present in the graph
vector<int>temp;
void dfs(int node,int par){
    temp.push_back(node);
    vis[node]=1;
    // here we are traversing all the neighbour node of that node
    for(auto v:g[node]){
        if(vis[v]==0){
   // here v is not equal to the par
     dfs(v,node);
        }else if(v==par){
          is_cycle=true;
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
    vis.assign(n+1,0);
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<vis[i]<<endl;
    }
    // here we are printing which node is visited
    for(auto v:temp){
        cout<<v<<" ";
    }
    
    cout<<endl;
    if(is_cycle){
        cout<<"cycle is present"<<endl;
    }else{
        cout<<"cycle is not present"<<endl;
    }



}
signed main(){
    solve();
}