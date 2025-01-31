#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using state=pair<int,int>;
#define F first
#define S second

int n,m;
const int inf=100;
vector<vector<char>>g;
vector<vector<int>>vis;
vector<vector<int>>dis;

/*
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
*/
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool is_valid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]!='#'){
          return true;
    }
    return false;
}
vector<state>neighbours(state node){
     vector<state>neigh;
     for(int k=0;k<4;k++){
        int x=node.F+dx[k];
        int y=node.S+dy[k];
        if(is_valid(x,y));
        neigh.push_back({x,y});
     }
     return neigh;
}
void bfs(state st_node){
    vis.assign(n,vector<int>(m,0));
    dis.assign(n,vector<int>(m,inf));
    queue<state>q;
    vis[st_node.F][st_node.S]=1;
    dis[st_node.F][st_node.S]=0;
    q.push(st_node);
    while(!q.empty()){
        state node=q.front();
        q.pop();
        for(state v:neighbours(node)){
             if(!vis[v.F][v.S]){
                vis[v.F][v.S]=1;
                dis[v.F][v.S]=dis[node.F][node.S]+1;
                  q.push(v);
             }
        }
    }
 

    
}
void solve(){
    cin>>n>>m;
    state st,en;
     g.assign(n,vector<char>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]=='s'){
                st={i,j};
            }else if(g[i][j]=='f'){
                en={i,j};
            }
            
        }
      
    }
    bfs(st);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<vis[i][j]<<" ";
        }
        cout<<endl;
    }
    if(!vis[en.F][en.S]){
        cout<<"not reachable"<<endl;
    }else{
        cout<<dis[en.F][en.S]<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dis[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    

 

}
/*
s.#...
..#...
#.#.#.
....#.
####..
f.....



*/
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}