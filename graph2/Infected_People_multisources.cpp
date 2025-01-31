#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using state=pair<int,int>;
int n,m;
vector<vector<int>>g;
vector<vector<int>>dis,vis;
queue<state>infect;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool is_valid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]!=0){
        return true;
    }
    return false;
}
vector<state>neighbours(state node){
     vector<state>neigh;
     for(int i=0;i<4;i++){
        int x=node.first+dx[i];
        int y=node.second+dy[i];
        if(is_valid(x,y)){
            neigh.push_back({x,y});
        }
     }
     return neigh;
}
void msbfs(){
    while(!infect.empty()){
        state node=infect.front();
        infect.pop();
        for(auto v:neighbours(node)){
            if(dis[v.first][v.second]==1e9){
                dis[v.first][v.second]=dis[node.first][node.second]+1;
                infect.push(v);
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    g.assign(n,vector<int>(m));
    dis.assign(n,vector<int>(m,1e9));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]==2){
                dis[i][j]=0;
                infect.push({i,j});
            }
        }
    }
    bool is_virus=false;
    // if(infect.empty()){
    //     //no virus is present
    //     is_virus=true;
    //     cout<<"-1"<<endl;
    //     return;
    // }
    msbfs();
    int maxi=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(g[i][j]!=0){
            maxi=max(maxi,dis[i][j]);

          }
        }
      
    }
    if(maxi==1e9){
      maxi=-1;
    }
    cout<<maxi<<endl;



}
signed main(){
    solve();
}