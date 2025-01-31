#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int>g[100100];
int dep[100100];
int par[100100];
bool isleaf[100100];
int subtreesz[100100];
int numchild[100100];
void dfs(int node,int parent,int depth){
    dep[node]=depth;
    par[node]=parent;
    subtreesz[node]=1;
    for(auto v:g[node]){
        if(v!=parent){
            numchild[node]++;
            dfs(v,node,depth+1);
            subtreesz[node]+=subtreesz[v];
        }
    }
    if(numchild[node]==0){
        isleaf[node]=1;
    }
}
void solve(){
    // n= nodes
    int n;
    cin>>n;
    //n-1 edge in the tree
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //for finding the every thing '
    dfs(1,0,0);
    for(int i=1;i<=n;i++){
        cout<<i<<" : "<<dep[i]<<" : "<<subtreesz[i]<<" : "<<numchild[i]<<" : "<<isleaf[i]<<endl;
    }

}
signed main(){
    solve();
}