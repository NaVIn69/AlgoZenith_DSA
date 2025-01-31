#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>parent;
vector<int>vis;
bool is_cycle=false;
vector<int>cntcyle;
vector<int>prefixorder;
// here  we havve taken the cntcyle to count the node, we count the node in the prefix order


// here we marking all the nodes with 1 means we have to traverse that all the node 
// 2 means we are going to traverse all the neighbours of that node
// // 3 means we have teaverse all the neighbours of that node
// void dfs(int node,int par){
//     parent[node]=par;
//     for(auto v:g[node]){
//         if(vis[v]==1){
//             dfs(v,node);
//         }else if(vis[v]==2){
//             // we find the back edge
//             // cycel is present
//             if(!is_cycle){
//                 vector<int>any_cycle;
//                 int curr=node;
//                 // while(curr!=v){
//                 //     any_cycle.push_back(curr);
//                 //     curr=parent[curr];
//                 // }
//                 any_cycle.push_back(curr);
//                 // reverse(any_cycle.begin(),any_cycle.end());
//                 // for(auto v:any_cycle){
//                 //     cout<<v<<" ";
//                 // }
//                 // cout<<endl;
//             }
//             cntcyle[node]++;
//             cntcyle[parent[v]]--;
//             is_cycle=true;
//         }else if(vis[v]==3){
//             // here we have find the cross edge 

//         }
//     }
//     vis[node]=3;
//     // here we have traversel all the neighbours of that node
// }
void dfs(int node ,int par){
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,node);
        }else if(v!=par){
          is_cycle=true;
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
    vis.assign(n+1,0);
    // here we have to visit all the node for dfs'
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0);
            if(is_cycle){
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;

    // here we have to count the number of node ,in how many cycle that node is present 

    


}
signed main(){
    solve();

}