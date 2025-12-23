#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,m;
vector<vector<int>>g;
vector<int>vis;

bool is_odd_cycle=false;
void dfs(int node,int col){
      vis[node]=col;
      for(auto v:g[node]){
            if(!vis[v]){
                dfs(v,3-col);
            }else if(col==vis[v]){
                 is_odd_cycle=true;
         
            }
      }
}
void solve(){
     cin>>n>>m;
     g.resize(n+1);
     vis.assign(n+1,0);
     for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
     }
     for(int i=1;i<=n;i++){
         if(!vis[i]&&g[i].size()!=0){
            dfs(i,1);
         }
     }
     if(is_odd_cycle){
        cout<<-1<<endl;
        return;
     }else{
        int cnt[3]={0};
        for(int i=1;i<=n;i++){
            cnt[vis[i]]++;
        }
        cout<<cnt[1]<<endl;
        for(int i=1;i<=n;i++){
            if(vis[i]==1){
                cout<<i<<" ";
            }
        }
        cout<<endl;
        cout<<cnt[2]<<endl;
        for(int i=1;i<=n;i++){
            if(vis[i]==2){
                cout<<i<<" ";
            }
        }
        cout<<endl;
     }
    

}
signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}