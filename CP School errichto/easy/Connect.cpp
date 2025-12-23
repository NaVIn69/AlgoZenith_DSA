#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n;
vector<vector<int>>arr;
int vis[100][100];

vector<pair<int,int>>v_start;
vector<pair<int,int>>v_end;

// Directions: Up, Right, Down, Left
int dx[4] = {-1, 0, 1, 0};  // change in row
int dy[4] = {0, 1, 0, -1};  // change in column
void dfs(int x,int y,vector<pair<int,int>>&v){
    vis[x][y]=1;
    v.push_back({x,y});
    // v_start.push_back({x,y});
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&!vis[nx][ny]&&arr[nx][ny]==0){
            dfs(nx,ny,v);
        }
    }

}

void solve(){
  cin>>n;
  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  arr.assign(n+1,vector<int>(n+1,-1));
  for (int i = 1; i <= n; i++) {
    string row;
    cin >> row;
    for (int j = 1; j <= n; j++) {
        arr[i][j] = row[j - 1] - '0';  // convert char to int
    }
}
//   for(int i=0;i<=n;i++){
//     for(int j=0;j<=n;j++){
//        cout<<arr[i][j]<<" ";
//     }
//     cout<<endl;
//  }
// cout<<endl;

  dfs(x1,y1,v_start);
  dfs(x2,y2,v_end);
//   cout<<v_start.size()<<endl;
//   cout<<v_end.size()<<endl;
int ans=1e9;
  for(int i=0;i<v_start.size();i++){
       int mini=0;
       int nx1=v_start[i].first;
       int ny1=v_start[i].second;
      for(int j=0;j<v_end.size();j++){
           int nx2=v_end[j].first;
           int ny2=v_end[j].second;
           int val=(nx2-nx1)*(nx2-nx1)+(ny2-ny1)*(ny2-ny1);
           ans=min(ans,val);

      } 
  }
  cout<<ans<<endl;

  


    

}
signed main(){
    solve();
}