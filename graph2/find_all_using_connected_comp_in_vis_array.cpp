#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis;
void dfs(int node,int comp_num){
   vis[node]=comp_num;
   for(auto v:g[node]){
    if(!vis[v]){
        dfs(v,comp_num);
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
 vis.resize(n+1,0);
 int num_comp=0;
 for(int i=1;i<=n;i++){
    if(!vis[i]){
        num_comp++;
        dfs(i,num_comp);
    }
 }
 vector<vector<int>>components;
 components.resize(n+1);
 for(int i=1;i<=n;i++){
    cout<<i<<":"<<vis[i]<<endl;
    components[vis[i]].push_back(i);
 }
 cout<<num_comp<<endl;
 for(int i=0;i<components.size();i++){
    for(auto v:components[i]){
        cout<<v<<" ";
    }
    cout<<endl;
 }
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
}