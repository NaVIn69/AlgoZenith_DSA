#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using state=pair<int,int>;
int n,m;
vector<vector<char>>g;
vector<vector<int>>vis;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
void dfs(state st,int comp){
    vis[st.first][st.second]=comp;
    for(int i=0;i<4;i++){
       int nx=dx[i]+st.first;
       int ny=dy[i]+st.second;
       if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny]!='#'){
           if(!vis[nx][ny]){
            dfs({nx,ny},comp);
           }
       }
    }
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,vector<int>(m+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           char ch;
           cin>>ch;
           g[i].push_back(ch);
        }
    }
  int comp=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(g[i][j]!='#'&&(!vis[i][j])){
            comp++;
            dfs({i,j},comp);
        }
    }
  }
  cout<<comp<<endl;



}
signed main(){
    solve();
}