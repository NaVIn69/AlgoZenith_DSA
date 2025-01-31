#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using state=pair<int,int>;
queue<state>q;
int n,m;
vector<vector<int>>g;
vector<vector<int>>vis;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void dfs(state sc_node){
   vis[sc_node.first][sc_node.second]=1;
   for(int i=0;i<4;i++){
      
   }

}


void solve(){
  cin>>n>>m;
  g.resize(n+1,vector<int>(m+1));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>g[i][j];
        if(g[i][j]==1){
            q.push({i,j});
        }
    }
  }
  vis.assign(n+1,vector<int>(m+1,0));


}
signed main(){
    solve();
}