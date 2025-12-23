#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,m;
vector<int>vis;// here each vis must store their component number
vector<vector<int>>g;

void dfs(int node,int comp_no){
     vis[node]=comp_no;
     for(auto v:g[node]){
         if(!vis[v]){
            dfs(v,comp_no);
         }
     }
}

void solve(){
 cin>>n>>m;
 g.resize(n+1);
 vis.assign(n+1,0);
vector<int>c(n+1);
  for(int i=1;i<=n;i++){
     cin>>c[i];
  }
  for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
  }
  int comp_no=0;
    for(int i=1;i<=n;i++){
         if(!vis[i]){
            comp_no++;
            dfs(i,comp_no);
         }
    }
    int ans=0;
    map<int,int>mpp;// each componete ka minimum value
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans+=c[i];
        }else{
            if(mpp.find(vis[i])!=mpp.end()){
                mpp[vis[i]]=min(mpp[vis[i]],c[i]);
            }else{
                mpp[vis[i]]=c[i];
            }
        }
    }
    for(auto x:mpp){
        ans+=x.second;
    }
    cout<<ans<<endl;
}
signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}