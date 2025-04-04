#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,k;
// here we have n*n chess board  we have to place the k knight such that they dont attack each other
int board[6][6];
int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};
bool check(int row,int col){
    // can i place the knights at (row,col) or not
    if(board[row][col]==1) return 0;
    // from that (row, col) we check all the 8 position , which is at the (2,1),(2,-1),(1,2),(1,-2)
   for(int i=0;i<8;i++){
      int nx=row+dx[i];
      int ny=col+dy[i];
      if(nx>=0&&nx<n&&ny>=0&&ny<n&&board[nx][ny]==1){
        return 0;
      }
   }

return 1;

}
int rec(int level,int k){
    // each grid component is the my level
    if(level==k){
        // means we have been placed k knights on the board
        // for(int i=0;i<6;i++){
        //     for(int j=0;j<6;j++){
        //         cout<<board[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        return 1;
    }
    // exploring all the level
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(check(i,j)){
                // can we place the knights
                board[i][j]=1;
                // move to next level
                ans+=rec(level+1,k);
                // unplace the knights , revert back
                board[i][j]=0;

            }
        }
    }
    return ans;
}
void solve(){
    cin>>n>>k;
    cout<<rec(n,k)<<endl;


}
signed main(){
    solve();
}