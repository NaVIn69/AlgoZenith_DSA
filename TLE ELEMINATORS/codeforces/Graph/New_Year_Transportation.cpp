#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

vector<vector<int>>g;
vector<int>vis;

void dfs(int node){
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

void solve(){
   int n,t;
   cin>>n>>t;
   g.resize(n+1);
   vis.assign(n+1,0);
   for(int i=1;i<n;i++){
       int a;
       cin>>a;
       g[i].push_back(i+a);
   }
   dfs(1);
   if(vis[t]){
    cout<<"YES"<<endl;
   }else{
    cout<<"NO"<<endl;
   }

}
signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}