#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis;
vector<int>temp;
void dfs(int sc_node){
    vis[sc_node]=1;
    temp.push_back(sc_node);
    for(auto node:g[sc_node]){
         if(!vis[node]){
            dfs(node);
         }
    }
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //printing the graph to visual stuff
    // for(int i=0;i<n;i++){
    //     cout<<"node"<<" "<<i<<endl;
    //     for(int j=0;j<g[i].size();j++){
    //         cout<<g[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vis.resize(n+1);
    dfs(1);
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }


    

}
signed main(){
    solve();
}