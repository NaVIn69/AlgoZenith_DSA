#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inf 1e9
#define F first 
#define S second
using state=pair<pair<int,int>,int>;
int n,m,k;
vector<vector<char>>g;
vector<vector<vector<int>>>dis;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool is_valid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m){
        return true;
    }
    return false;
}
vector<state>neighbours(state node){
    vector<state>neigh;
    for(int i=0;i<4;i++){
        int x=node.F.F+dx[i];
        int y=node.F.S+dy[i];
        if(is_valid(x,y)){
        int z=node.S;
        //z tell me about the how much we have break the wall to reach at (i,j) by shortest path
        //here is cell ke neighbour ke pass wall hai then we have to break that wall
        //after breaking wall if z<=k then we can say it is valid neighbour 
        if(g[x][y]=='#')z+=1;
        //z>k then find another valid neighbour
        if(z>k) continue;
        else neigh.push_back({{x,y},z});
        }

    }
    return neigh;
}
void bfs(state sc_node){
     dis.assign(n,vector<vector<int>>(m,vector<int>(k+1,inf)));
     queue<state>q;
     dis[sc_node.F.F][sc_node.F.S][sc_node.S]=0;
     q.push(sc_node);
     while(!q.empty()){
         state node =q.front();
         q.pop();
         for(state v:neighbours(node)){
            if(dis[v.F.F][v.F.S][v.S]==inf){
                dis[v.F.F][v.F.S][v.S]=dis[node.F.F][node.F.S][node.S]+1;
                q.push(v);
            }
         }
     }

}

void solve(){
  cin>>n>>m>>k;
  pair<int,int> st,en;
  g.assign(n,vector<char>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
         cin>>g[i][j];
         if(g[i][j]=='s'){
            st={i,j};
         }else if(g[i][j]=='e'){
            en={i,j};
         }
    }
  }
  bfs({st,0});
  int ans=INT_MAX;
   for(int bomb=0;bomb<=k;bomb++){
       ans=min(ans,dis[en.F][en.S][bomb]);
   }
  //here we have break zero wall and we are at starting position
  cout<<ans<<endl;
}
signed main(){
    solve();
}