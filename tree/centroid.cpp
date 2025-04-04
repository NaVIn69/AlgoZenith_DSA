#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<int>g[100100];
int dep[100100];
int par[100100];
int subtreesz[100100];
int vis[100100];
void dfs(int node,int parent,int depth){
    dep[node]=depth;
    par[node]=parent;
    subtreesz[node]=1;
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,node,depth+1);
            subtreesz[node]+=subtreesz[v];
        }
    }

}
// here we have find the centroid of the tree , 
// centroid of any tree ->  size of any child node must be less than equal to  subtreesz[that tree]/2 .
vector<int>centriod;
// here we have to find the centriod , 
void centriod_find(int node,int subtreesz){
      // here we have given the subtreesz of that node , 
      // here we have to travel 
      
}

void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
  



}
signed main(){
    solve();
}