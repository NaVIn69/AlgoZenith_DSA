#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
int n,m,q;
vector<vector<int>>g;
vector<int>vis;
void dfs(int sc_node,int comp){
     vis[sc_node]=comp;
     for(auto node:g[sc_node]){
        if(!vis[node]){
            dfs(node,comp);
        }
     }
}
void solve(){
    cin>>n>>m>>q;
    g.resize(n+1);
   vis.resize(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int comp=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            comp++;
            dfs(i,comp);
        }
    }
    // printing all the connected componenet
    vector<vector<int>>connected_comp;
    connected_comp.resize(comp+1);
    // here each index of connected_comp tells me about the component number
    for(int i=1;i<=n;i++){
          connected_comp[vis[i]].push_back(i);
    }
    // for(int j=1;j<=comp;j++){
    //     for(int i=0;i<connected_comp[j].size();i++){
    //         cout<<connected_comp[j][i]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(q--){
        int ch;
        cin>>ch;
        if(ch==1){
            int x;
            cin>>x;
            cout<<connected_comp[vis[x]].size()<<endl;
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }

}