#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using state=pair<int,int>;
int n,m;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
vector<vector<int>>arr;
vector<vector<int>>vis;
bool is_valid(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&arr[x][y]!=1){
        return true;
    }
    return false;
}
vector<state>neighbours(state sc_node){
  vector<state>neighs;
  for(int i=0;i<4;i++){
    int nx=sc_node.first+dx[i];
    int ny=sc_node.second+dy[i];
    if(is_valid(nx,ny)){
        neighs.push_back({nx,ny});
    }
  }
  return neighs;
}
// here vis[i][j] tells me about the component number and it can traverse in all the 4 direction
void bfs(state sc_node,int comp){
    vis[sc_node.first][sc_node.second]=comp;
    queue<state>q;
    q.push(sc_node);
    while(!q.empty()){
       state node=q.front();
       q.pop();
       for(auto v:neighbours(node)){
           if(!vis[v.first][v.second]){
            vis[v.first][v.second]=comp;
            q.push(v);
           }
        
       }
    }

    
}

void solve(){
  cin>>n>>m;
  arr.assign(n+1,vector<int>(m+1,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>arr[i][j];
       
    }
 
  }
//   for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         cout<<arr[i][j]<<" ";
       
//     }
//     cout<<endl;
//   }
//   here visited array tell me about from which component it belongs

//   here we are visiting all the nodes // where we find the 0 , we traversing to the all the neighbours where we can reach
vis.assign(n,vector<int>(m,0));
  int num_comp=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1) continue;
            if(!vis[i][j]){
                num_comp++;
                bfs({i,j},num_comp);
            }
        }
    }
  vector<vector<state>>all_comp;
  int sz=(n*m)/2;
  all_comp.resize(sz+2);
 
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        all_comp[vis[i][j]].push_back({i,j});
    }
  }
  // here all_comp tell me about that all_comp[vis[i][j]] 
  // has all the nodes which belong to the vis[i][j] component
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(arr[i][j]==1){
            cout<<"1"<<" ";
        }else{
            if(all_comp[vis[i][j]].size()==1){
                cout<<"0"<<" ";
            }else{
            cout<<all_comp[vis[i][j]].size()<<" ";
            }
        }
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