#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// n ->number of nodes  m->number of edges
int n,m;
// here we are takin vector<vector<int>>g represent that each node ke jo bhi usske neighbour hai i=usko us node ke vector me dal do
vector<vector<int>>g;
// here vis represent the visited array means it tells me about which nodes is traversed or not
vector<int>vis;
vector<int>temp;
void dfs(int node,int comp_no){
    vis[node]=comp_no;
    temp.push_back(node);
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,comp_no);
        }
    }

}
void solve(){
    int q;
    cin>>n>>m>>q;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        // here a and b are the neighbour nodes
        cin>>a>>b;
        // directed graph
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vis.resize(n+1,0);
    int comp_no=0;
    // dfs tells me about jo bhi node ko touch krega uske sare connected nodes ko touch kr ke aa jayega
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            comp_no++;
            dfs(i,comp_no);
        }
    }
      vector<vector<int>>compon(comp_no+1);
    for(int i=1;i<=n;i++){
        // cout<<i<<":"<<vis[i]<<endl;
         compon[vis[i]].push_back(i);
    }
    while(q--){
        int p;
        cin>>p;
        if(p==1){
            int x;
            cin>>x;
            cout<<compon[vis[x]].size()<<endl;
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
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
