#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis;
bool is_oddcycle=false;
void dfs(int sc_node,int color){
    vis[sc_node]=color;
    for(auto v:g[sc_node]){
        if(!vis[v]){
       
        dfs(v,3-color);
        }else if(vis[v]==vis[sc_node]){
           is_oddcycle=true;
        }
    }
}
void solve(){
  cin>>n>>m;
//  g.assign(n,vector<int>(m,0));
g.resize(n+1);
for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
vis.assign(n+1,0);
for(int i=1;i<=n;i++){
    if(!vis[i]){
        dfs(i,1);
    }
    if(is_oddcycle){
        cout<<"NO"<<endl;
        return;
    }
}
cout<<"YES"<<endl;
 

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}