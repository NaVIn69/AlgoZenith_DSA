#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int>g[200200];
int dep[200200];
int par[200200];
void dfs(int node,int parent,int depth){
    dep[node]=depth;
    par[node]=parent;
    for(auto v:g[node]){
        if(v!=parent){
            dfs(v,node,depth+1);
        }
    }
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
    int maxch=1;
    for(int j=2;j<=n;j++){
        if(dep[j]>dep[maxch]){
            maxch=j;
        }
    }
    
    dfs(maxch,0,0);
    maxch=1;
    for(int j=2;j<=n;j++){
        if(dep[j]>dep[maxch]){
            maxch=j;
        }
    }
   
    cout<<dep[maxch]<<endl;


}
signed main(){
    solve();
}