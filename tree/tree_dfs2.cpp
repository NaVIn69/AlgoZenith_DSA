#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int>g[100100];
int dep[100100];
int par[100100];
int subtreesz[100100];
int numChild[100100];
bool isleaf[100100];

void dfs(int node,int parent,int depth){
    dep[node]=depth;
    par[node]=parent;
    numChild[node]=0;
    subtreesz[node]=1;
    for(auto v:g[node]){
        if(v!=parent){
            numChild[node]++;
            dfs(v,node,depth+1);
            subtreesz[node]+=subtreesz[v];
        }
    }
    if(numChild[node]==0){
        isleaf[node]=1;
    }

}
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int u=5;
    int v=7;
    dfs(u,0,0);
    for(int i=1;i<=n;i++){
        cout<<dep[i]<<" "<<subtreesz[i]<<" "<<numChild[i]<<" "<<par[i]<<" "<<isleaf[i]<<endl;
    }
    cout<<endl;
    
   

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}