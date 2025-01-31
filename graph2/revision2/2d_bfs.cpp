#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using state=pair<int,int>;
int n,m;
vector<vector<char>>g;
vector<vector<int>>vis;
vector<vector<int>>dis;
vector<vector<state>>parent;

/// @brief for knight version 
int dx_k[8]={2,1,-1,-2,-2,-1,1,2};
int dy_k[8]={-1,-2,-2,-1,1,2,2,1};
/// simple 4 dirsction
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
    state st,f;

void bfs(state st){
    vis.assign(n+1,vector<int>(m+1,0));
    dis.assign(n+1,vector<int>(m+1,1e9));
    parent.assign(n+1,vector<state>(m+1,{-1,-1}));
    queue<state>q;
    q.push(st);
    dis[st.first][st.second]=0;
    while(!q.empty()){
        state node=q.front();
        q.pop();
        int x=node.first;
        int y=node.second;
        if(vis[x][y])continue;
        vis[x][y]=1;
        for(int i=0;i<4;i++){
           int nx=dx[i]+x;
           int ny=dy[i]+y;
           if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny]!='#'){
               if(!vis[nx][ny]&&dis[nx][ny]>dis[x][y]+1){
                parent[nx][ny]={x,y};
                  dis[nx][ny]=dis[x][y]+1;
                  q.push({nx,ny});
               }
           }
        }
    }


}
void print_path(){
    vector<state>path;
    // path.push_back(f);
 
    state temp=f;
    // cout<<parent[temp.first][temp.second].first<<" "<<parent[temp.first][temp.second].second<<endl;
    while(temp != (make_pair(-1LL,-1LL))){
        path.push_back(temp);
       temp=parent[temp.first][temp.second];
    
       
        // cout<<"navin"<<" ";
    }
    reverse(path.begin(),path.end());
    for(auto v:path){
        cout<<"("<<v.first<<" "<<v.second<<" "<<")"<<","<<" ";
    }
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1);

    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
        char ch;
        cin>>ch;
        if(ch=='S'){
            st={i,j};
        }else if(ch=='F'){
            f={i,j};
        }
        g[i].push_back(ch);
       }
    }

    bfs(st);
    if(dis[f.first][f.second]==1e9){
        cout<<"not reachable"<<endl;
    }else{
        cout<<dis[f.first][f.second]<<endl;
        print_path();
    }


}
signed main(){
  solve();
}
/*
S . # . . .
. . # . . .
# . # . # .
. . . . # .
# # # # . .
F . . . . .
*/