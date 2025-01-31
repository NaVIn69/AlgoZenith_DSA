#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int> g[100100];
int dep[100100];
int par[100100][20];
// here we have the common ancestore of u and v in a tree using the binary lifting

// this is the normal dfs 
// where 
void dfs(int node,int prev,int depth ){
    par[node][0]=prev;
    dep[node]=depth;
    // here we are building the binary lifting for all the node
    for(int i=1;i<20;i++){
        par[node][i]=par[par[node][i-1]][i-1];
    }
    // dfs
    for(auto v:g[node]){
        if(v!=prev){
            dfs(v,node,depth+1);
        }
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v]){
        swap(u,v);
    }
    // here we making them at the same level
    // from x we are moving the k steps
    for(int i=19;i>=0;i--){
    
        if((dep[u]-dep[v])&(1<<i)){
           u=par[u][i];
        }
    }
    if(u==v) return u;
    // here we are checking them 
    for(int i=19;i>=0;i--){
        if(par[v][i]!=par[u][i]){
            v=par[v][i];
            u=par[u][i];
        }
    }
    return par[u][0];
}
void solve(){
 int n;
 cin>>n;
 for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
 }
 dfs(1,0,0);
 for(int i=1;i<=n;i++){
    for(int j=0;j<20;j++){
        if(par[i][j]!=0){
        cout<<par[i][j]<<" ";
        }
    }
    cout<<endl;
 }


}
signed main(){
   
    solve();
}