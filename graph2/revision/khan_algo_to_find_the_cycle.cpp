#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>col;
vector<int>parent;
int cycle=0;
void dfs(int node,int par){
    col[node]=2;
    parent[node]=par;
    for(auto v:g[node]){
        if(col[v]==1){
        dfs(v,node);
        }else if(col[v]==2){
            // node - v back edge
            // cycle is presnt
            if(cycle==0){
                int temp=node;
                vector<int>any_cycle;
                while(temp!=v){
                    any_cycle.push_back(temp);
                    temp=parent[temp];
                }
                any_cycle.push_back(v);
                reverse(any_cycle.begin(),any_cycle.end());
                for(auto v:any_cycle){
                    cout<<v<<" ";
                }
                cout<<endl;
            }
            cycle=1;


        }else if(col[v]==3){
            // node - v cross edge

        }
    }
    //here we have been visited all the neighbours of node
    col[node]=3;
    
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        // g[b].push_back(a);
    }
    col.assign(n+1,1);
    parent.resize(n+1);
    for(int i=1;i<=n;i++){
        if(col[i]==1){
            dfs(i,0);
        }
    }

}
signed main(){
    solve();
}
