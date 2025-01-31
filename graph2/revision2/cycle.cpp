#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m;
vector<vector<int>>g;
vector<int >col,parent;
bool is_cycle=false;
void dfs(int sc_node,int par){
    col[sc_node]=2;
    parent[sc_node]=par;
    // means we have to travell all the neighbours of the node
    for(auto v:g[sc_node]){
        if(col[v]==1){
          dfs(v,sc_node);
        }else if(col[v]==2){
            // node v and sc_node has the backedge
            if(!is_cycle){
                vector<int>path;
                int temp=sc_node;
                while(temp!=v){
                    path.push_back(temp);
                    temp=parent[temp];
                }
                path.push_back(v);
                reverse(path.begin(),path.end());
                for(auto v:path){
                    cout<<v<<" ";
                }
            }
            is_cycle=1;


        }else if(col[v]==3){
            // we have the cross edge 
        }
        col[v]=3;
    }

}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    col.assign(n+1,1);

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
    return 0;
}