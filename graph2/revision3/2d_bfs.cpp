#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using state =pair<int,int>;
int n,m;
state st,en;
vector<vector<char>>g;
vector<vector<int>>dis,vis;
vector<vector<pair<state,char>>>parent;
// means parent node se 
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
char dir[]={'D','U','L','R'};
void bfs(state sc_node){
    dis.assign(n+1,vector<int>(m+1,1e9));
    vis.assign(n+1,vector<int>(m+1,0));
    parent.assign(n+1,vector<pair<state,char>>(m+1,{{-1,-1},'a'}));
    queue<state>q;
    q.push(sc_node);
    dis[sc_node.first][sc_node.second]=0;
    while(!q.empty()){
        state node=q.front();
        q.pop();
        int x=node.first;
        int y=node.second;
        if(vis[x][y]) continue;
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
          if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny]!='#'){
              if(!vis[nx][ny]&&dis[nx][ny]>dis[x][y]+1){
                dis[nx][ny]=dis[x][y]+1;
                parent[nx][ny]={{x,y},dir[i]};
                q.push({nx,ny});
              }
          }
        }
    }

}

void solve(){
    cin>>n>>m;
    g.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            if(ch=='A'){
                st={i,j};
            }else if(ch=='B'){
                en={i,j};
            }
            g[i].push_back(ch);
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<g[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    bfs(st);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(dis[en.first][en.second]==1e9){
        cout<<"NO"<<endl;
        return ;
    }
   
    cout<<"YES"<<endl;
    cout<<dis[en.first][en.second]<<endl;
    state temp=en;
    string direction="";
    while(temp!=st){
        pair<state,char> p= parent[temp.first][temp.second];
        direction+=p.second;
        temp=p.first;
    }
    reverse(direction.begin(),direction.end());
    cout<<direction<<endl;
    // for(auto c:direction){
    //     cout<<c;
    // }
    cout<<endl;



      



}
signed main(){
    solve();
}