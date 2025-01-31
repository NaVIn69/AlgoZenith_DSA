#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>parent;
vector<int>col;
bool is_cycle=false;
void dfs(int node,int par){       
    parent[node]=par;
    col[node]=2;
    for(auto v:g[node]){
        if(v==parent[node]){
            continue;
        }
        if(col[v]==1){
            dfs(v,node);
      }else if(col[v]==2){
        is_cycle=true;
      }else if(col[v]==3){

      }
    }
    col[node]=3;
   
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    col.assign(n+1,1);
    parent.assign(n+1,0);
    for(int i=0;i<n;i++){
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
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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
