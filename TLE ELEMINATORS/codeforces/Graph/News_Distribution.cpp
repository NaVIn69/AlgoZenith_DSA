#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,m;
vector<vector<int>>g;
vector<int>vis;

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
  for(int i=0;i<m;i++){
       int k;
       cin>>k;
       if(k==1){
        int x;
        cin>>x;
        continue;
       }
       int prev=-1;
       for(int j=0;j<k;j++){
        int curr;
        cin>>curr;
             if(j==0){
               prev=curr;
             }else{
                g[prev].push_back(curr);
                g[curr].push_back(prev);
                prev=curr;
             }
       }
  }
  int comp_no=0;
     for(int i=1;i<=n;i++){
         if(!vis[i]){
            comp_no++;
            dfs(i,comp_no);
         }
     }
     map<int,int>mpp;
     for(int i=1;i<=n;i++){
         mpp[vis[i]]++;
     }
     for(int i=1;i<=n;i++){
        cout<<mpp[vis[i]]<<" ";
     }
     cout<<endl;

}
signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}