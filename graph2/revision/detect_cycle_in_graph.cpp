#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>parent;
vector<int>col;
bool is_cycle=false;
void dfs(int node,int par){
    col[node]=2;
    parent[node]=par;
    for(auto v:g[node]){
        // here we are travesring all the node of the graph
        if(col[v]==1){
            // we have to visit all the neighbours of that node v
            dfs(v,node);
        }else if(col[v]==2){
            // we have to traversing all the neighbours of that node
            // here we find the cycle we have to print the cycle 
        
            // if(!is_cycle){
            // vector<int>cycle;
            // int curr=node;
            // // 
            // while(curr!=v){
            //   cycle.push_back(curr);
            //   curr=parent[curr];
            // }
            // cycle.push_back(curr);
            // reverse(cycle.begin(),cycle.end());
            // for(auto v:cycle){
            //     cout<<v<<" ";
            // }
            // cout<<endl;
            // }
             is_cycle=true;

        }else if(col[v]==3){
            // means cross edge is present
        }
    
    }
  
    col[node]=3;
}
void solve(){
   cin>>n>>m;
   g.resize(n+1);
   col.assign(n+1,1);
   parent.resize(n+1);
   for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    // g[b].push_back(a);
   }

   for(int i=1;i<=n;i++){
    if(col[i]==1){
        dfs(i,0);
    }
   }
   cout<<is_cycle<<endl;


}
signed main(){
    solve();
}