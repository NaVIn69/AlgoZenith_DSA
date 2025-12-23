#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int>g[100100];
int subtreesz[100100];
int numChild[100100];
int dep[100100];
int par[100100];
bool isleaf[100100];
void dfs(int node,int parent,int depth){
    par[node]=parent;
    dep[node]=depth;
    subtreesz[node]=1;
    numChild[node]=0;
    for(auto v:g[node]){
        // here we are traversing all the child of that node
        if(v!=parent){
            numChild[node]++;
         dfs(v,node,depth+1);
         // first traversing the child node then we go 
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
   // here depth [maxch ] tells me aboout tha dep[]
    cout<<dep[maxch]<<endl;

}
signed main(){
    solve();
}