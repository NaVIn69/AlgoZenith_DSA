 #include<bits/stdc++.h>
 using namespace std;
 #define int long long
 #define endl "\n"
 int n,m;
 vector<vector<int>>g;
 vector<int>vis;
 bool is_bipartit=false;
 void dfs(int sc_node,int color){
        vis[sc_node]=color;
        for(auto node:g[sc_node]){
            if(!vis[node]){
                dfs(node,3-color);
            }else if(vis[node]==vis[sc_node]){
                is_bipartit=true;
               
            }
        }
 }
 void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,1);
        }
    }
    if(is_bipartit){
       cout<<"odd cycle or graph is bipartite"<<endl;
    }else{
        cout<<"graph is not bipartite"<<endl;
    }



 }
 signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    while(t--){
    solve();
    }
 }