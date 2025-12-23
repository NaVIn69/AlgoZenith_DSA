 #include<bits/stdc++.h>
 using namespace std;
 #define int long long
 #define endl "\n"
 int n,m;
 vector<vector<int>>g;
 vector<int>vis;
 vector<int>parent;

 void dfs(int sc_node,int comp){
      vis[sc_node]=comp;
      for(auto v:g[sc_node]){
          if(!vis[v]){
              dfs(v,comp);
          }
      }
 }
 bool check_bipartite=true;
 void check(int sc_node,int col){
     vis[sc_node]=col;
     for(auto v:g[sc_node]){
         if(!vis[v]){
            check(v,3-col);
         }else if(vis[v]==vis[sc_node]){
             check_bipartite=false;
         }
     }
 }
 // for printing the cycle
 bool check_cycle=false; // no cycle is present in the graph
 void cycle(int sc_node,int par){
     vis[sc_node]=1;
     parent[sc_node]=par;
     for(auto v:g[sc_node]){
         if(!vis[v]){
            cycle(v,sc_node);
         }else if(v!=par){
            
            // in one graph we can find many cycle and here we have to print 
             if(!check_cycle){
                vector<int>path;
                int temp=node;
                while(temp!=v){
                    path.push_back(temp);
                    temp=parent[temp];
                }
                path.push_back(v);
                reverse(path.begin(),path.end());
                for(auto v:path){
                    cout<<v<<" ";
                }
                cout<<endl;
             }
         }
     }

 }
 void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    parent.assign(n+1,-1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int comp=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            comp++;
            dfs(i,comp);
        }
    }

 }
 signed main(){
    solve();
 }