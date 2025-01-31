#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int ans=0;
int queens[14];
int grid[14][14];
int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};
bool check(int level,int col){
    if(grid[level][col]==1) return 0;
    for(int i=0;i<8;i++){
        int new_x=level+dx[i];
        int new_y=col+dy[i];
        if(new_x>=0&&new_x<n&&new_y>=0&&new_y<n&&grid[new_x][new_y]==1){
            return 0;
        }
    }
    return 1;
}
// here my level is number of knight placed
void rec(int level){
// here (row,col) is the level
// we can place the queens at each and every place
if(level==k){
    ans++;
    return ;
}
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(check(i,j)){
          grid[i][j]=1;
          rec(level+1);
          grid[i][j]=0;
        }
    }
  }


}
void solve(){
    cin>>n>>k;
    rec(0);
    cout<<ans<<endl;
    for(int i=1;i<=k;i++){
        ans=ans/i;
    }
    cout<<ans<<endl;

  

}
signed main(){
    solve();
}