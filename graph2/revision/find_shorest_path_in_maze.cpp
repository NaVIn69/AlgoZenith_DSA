#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define F first
#define S second
using state=pair<int,int>;
int n,m;
vector<vector<char>>g;
vector<vector<int>>dis,vis;
vector<vector<state>>parent;
vector<state>path;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool valid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]!='#'){
        return true;
    }
    return false;
}
vector<state> neighbours(state node){
    vector<state>neigh;
    for(int i=0;i<4;i++){
       int nx=node.F+dx[i];
       int ny=node.S+dy[i];
     if(valid(nx,ny)){
         neigh.push_back({nx,ny});
     }
    }
    return neigh;
}

void bfs(state sc_node){
    vis.assign(n+1,vector<int>(m+1,0));
    dis.assign(n+1,vector<int>(m+1,1e9));
    parent.assign(n+1,vector<state>(m+1,{-1,-1}));
    dis[sc_node.F][sc_node.S]=0;
    vis[sc_node.F][sc_node.S]=1;
    parent[sc_node.F][sc_node.S]={0,0};
    queue<state>q;
    q.push(sc_node);
    while(!q.empty()){
        state node=q.front();
        q.pop();
    for( auto v:neighbours(node)){
        // here v is the pair
        if(!vis[v.F][v.S]){
        dis[v.F][v.S]=dis[node.F][node.S]+1;
        vis[v.F][v.S]=1;
        parent[v.F][v.S]=node;
        q.push(v);
        }
    }

    }

}
void print_path(state st,state en){
      vector<state>path;
      state temp=en;
      while(temp!=st){
        path.push_back(temp);
        temp=parent[temp.F][temp.S];
      }
      path.push_back(st);
      reverse(path.begin(),path.end());
     for(state v:path){
        cout<<v.F<<" "<<v.S<<endl;
    }
}


void solve(){
 cin>>n>>m;
 state intial,final;
 // here n is the row, m is column
 g.assign(n,vector<char>(m));
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>g[i][j];
        if(g[i][j]=='s'){
            intial={i,j};
        }else if(g[i][j]=='e'){
            final={i,j};
        }
    }
 }


 bfs(intial);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
       cout<<"{"<<parent[i][j].F<<" "<<parent[i][j].S<<"}"<<" ";
    }
    cout<<endl;
  }
  
 if(dis[final.F][final.S]==1e9){
    cout<<"NOt reached"<<endl;
 }else{
    cout<<dis[final.F][final.S]<<endl;
    print_path(intial,final);
 }
 



}
signed main(){
    solve();
}