#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m,q;
vector<vector<int>>g;
vector<int>vis;
void dfs(int node,int comp){
   vis[node]=comp;
   for(auto v:g[node]){
      if(vis[v]==0){
        dfs(v,comp);
      }
   }
}

void solve(){
    cin>>n>>m>>q;
    g.resize(n+1);
    vis.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int num_comp=0;
    
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            num_comp++;
            dfs(i,num_comp);
        }
    }
    vector<vector<int>>all_comp;
    all_comp.resize(num_comp+1);
    for(int i=1;i<=n;i++){
        all_comp[vis[i]].push_back(i);
    }
    while(q--){
        int ch;
        cin>>ch;
        if(ch==1){
            int x;
            cin>>x;
            // here  we have to find the size of connected component
            // vis[x] tells me component number
            cout<<all_comp[vis[x]].size()<<endl;
        }else{
            int x,y;
            cin>>x>>y;
            if(vis[x]==vis[y]){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
   


  
}
signed main(){
    solve();
}