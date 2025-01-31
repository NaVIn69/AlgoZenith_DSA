#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis;
vector<int>par;
bool is_cycle=false;
void dfs(int sc_node,int parent){
    par[sc_node]=parent;
     vis[sc_node]=1;
     for(auto node:g[sc_node]){
        if(!vis[node]){
            dfs(node,sc_node);
        }else if(node!=parent){
            // here node 
             if(!is_cycle){
                vector<int>cycle_path;
                int temp=sc_node;
                cycle_path.push_back(sc_node);
                while(temp!=node){
                    temp=par[temp];
                    cycle_path.push_back(temp);
                }
                // cycle_path.push_back(temp);
                reverse(cycle_path.begin(),cycle_path.end());
                for(auto v:cycle_path){
                    cout<<v<<" ";
                }
                cout<<endl;
                
             }
             is_cycle=true;
        }  
     }
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1,0);
    par.assign(n+1,-1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0);
        }
    }
    if(is_cycle){
        cout<<"cycle is present"<<endl;
    }else{
        cout<<"cycle is not present"<<endl;
    }


}
signed main(){
   solve();
}