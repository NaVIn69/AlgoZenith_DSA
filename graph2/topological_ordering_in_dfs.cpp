#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis,topo;
void dfs(int node){
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
    topo.push_back(node);
}
//here we are find the longest path in DAG
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(topo.begin(),topo.end());
    for(auto v:topo){
        cout<<v<<" ";
    }
    cout<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}