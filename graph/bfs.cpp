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
// dis vector tells me about the distance of ith node frome sources node
vector<int>dis;
// bfs -> means breadth first search means we search the element level wise
void bfs(int sc_node){
    // we are using the queue 
    queue<int>q;
    vis[sc_node]=1;
    dis[sc_node]=0;
    q.push(sc_node);
    while(!q.empty()){
        int node=q.front();
        q.pop();
       for(auto v:g[node]){
         if(!vis[v]){
            vis[v]=1;
            dis[v]=dis[node]+1;
            q.push(v);
         }
       }

    }
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        // here a and b are the neighbour nodes
        cin>>a>>b;
        // directed graph
        g[a].push_back(b);
    }
    vis.resize(n+1,0);
    dis.assign(n+1,1e9);
    bfs(1);
    for(int i=1;i<=n;i++){
        cout<<i<<":"<<vis[i]<<" "<<dis[i]<<endl;
    }
   
    
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
