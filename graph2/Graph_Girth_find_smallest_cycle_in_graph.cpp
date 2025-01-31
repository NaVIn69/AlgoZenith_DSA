#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>col;
vector<int>parent;
int ans=INT_MAX;
bool is_cycle=false;
void dfs(int sc,int par){
    parent[sc]=par;
    for(auto v:g[sc]){
        if(!col[v]){
            col[v]=1;
            dfs(v,sc);
        }else if(v!=par){
            //backedge
            is_cycle=true;
            int cnt=1;
            int temp=sc;
            while(temp!=v){
                cnt++;
                temp=parent[temp];
            }
            cnt++;
            ans=min(ans,cnt);  
        }
}
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    col.assign(n+1,1);
    parent.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
   for(int i=1;i<=n;i++){
      if(col[i]==1){
        dfs(i,0);
      }
   }
   if(is_cycle){
    cout<<ans<<endl;
   }else{
    cout<<"-1"<<endl;
   }

}
signed main(){
    solve();
}