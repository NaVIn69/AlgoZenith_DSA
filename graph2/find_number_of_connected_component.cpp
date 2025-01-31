#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//undirected graph
int mod=1e9+7;
int n,m;
vector<vector<int>>g;
vector<int>vis;
void dfs(int node,int &cnt_sz,vector<int>&comp){
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v]){
            comp.push_back(v);
            cnt_sz++;
            dfs(v,cnt_sz,comp);
        }
    }
}
//here we have been find the set of component and size of component

void solve(){
   cin>>n>>m;
   g.resize(n+1);
   for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    //undirected
    g[b].push_back(a);
   }
   vis.resize(n+1,0);
   int num_comp=0;
   for(int i=1;i<=n;i++){
    
    if(!vis[i]){
        int ans=1;
        vector<int>comp;
        comp.push_back(i);
        dfs(i,ans,comp);
        cout<<ans<<" ";
        for(int i=0;i<comp.size();i++){
            cout<<comp[i]<<" ";
        }
        cout<<endl;
        num_comp++;
    }
   }
 
   cout<<num_comp<<endl; 
}
signed main(){
    solve();
}