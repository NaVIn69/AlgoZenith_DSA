#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
using ii=pair<int,int>;
using state =pair<ii,int>;
// here ii tells me {i,j} and int tells me about the how many walls has been broken upto (i,k)
int n,m,k;
string arr[1000];
int dis[500][500][500] ;
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
bool is_valid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m){
        return true;
    }
    return false;
}
// this dist tells me about the from sources node to (i,j,x) we  have have broken x walls
// here we have to use normal bfs -> this give me the shortest path from (sources node) to (final node)

void bfs(state sc_node){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int z=0;z<=k;z++){
                dis[i][j][z]=1e9;
            }
        }
    }
    queue<state>q;
    q.push(sc_node);
    dis[sc_node.first.first][sc_node.first.second][sc_node.second]=0;
     while(!q.empty()){
        state node=q.front();
        q.pop();
        // here we have to go 4 direction we have to check
        for(int dir=0;dir<4;dir++){
             int nx=node.first.first+dx[dir];  
             int ny=node.first.second+dy[dir];
             if(is_valid(nx,ny)){
                 int newwall= node.second+ arr[nx][ny]=='#'?1:0 ;
                 if(dis[nx][ny][newwall]>dis[node.first.first][node.first.second][node.second]+1){
                    dis[nx][ny][newwall]=dis[node.first.first][node.first.second][node.second]+1;
                    q.push({{nx,ny},newwall});
                 }
             }

      }
     }

}

void solve(){
  cin>>n>>m>>k;
  ii st,en;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    for(int j=0;j<m;j++){
        if(arr[i][j]=='s'){
            st={i,j};
        }else if(arr[i][j]='f'){
            en={i,j};
        }
    }
  }
  bfs({st,0});
  int ans=1e9;
  for(int i=0;i<=k;i++){
    ans=min(ans,dis[en.first][en.second][i]);
    // when we have ith break wall then what is the distance array
  }
cout<<ans<<endl;

}
signed main(){
    solve();
}