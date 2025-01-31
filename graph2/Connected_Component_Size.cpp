#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using state=pair<int,int>;
#define F first
#define S second
int n,m;
int temp;
vector<vector<int>>g;
vector<vector<int>>vis;
vector<state>path;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
bool is_valid(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=m&&g[x][y]!=1){
        return true;
    }
    return false;
}
vector<state>neighbours(state node){
    vector<state>neigh;
    for(int i=0;i<4;i++){
        int x=node.F+dx[i];
        int y=node.S+dy[i];
        if(is_valid(x,y)){
                neigh.push_back({x,y});
        }
    }
    return neigh;
         
}
void dfs(state sc_node){
    path.push_back(sc_node);
    if(! vis[sc_node.F][sc_node.S]) temp++;
    vis[sc_node.F][sc_node.S]=1;
    for(auto v:neighbours(sc_node)){
        if(!vis[v.F][v.S]){
           dfs(v);
    }

    }
}

     

void solve(){
  cin>>n>>m;
  g.assign(n+1,vector<int>(m+1,0));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        cin>>g[i][j];
    }
  }
  vis.assign(n+1,vector<int>(m+1,0));
  for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
            if(g[i][j]!=1&&!vis[i][j]){
                path.clear();
                temp=0;
                dfs({i,j});
                if(temp==1){
                    temp=0;
                }
               for(auto v:path){
                g[v.F][v.S]=temp;
               }
            }
          }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        cout<<g[i][j]<<" ";
    }
    cout<<endl;
  }
  

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}