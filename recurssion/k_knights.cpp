#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int ans=0;
int board[14][14];
// here dx and dy is the coordinate where it attack the knight at the 0th index
int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};
bool check(int row,int column){
    if(board[row][column]==1) return 0;
    for(int pos=0;pos<8;pos++){
       int nx=row+dx[pos];
       int ny=column+dy[pos];
       // nx ,ny are getting attack
       if(nx<n&&nx>=0&&ny<n&&ny>=0 && board[nx][ny]==1){
        return 0;
       }
       
    }
    return 1;

}
void rec(int level){ // here level=no of knight placed
// level is the number of cells 
// we have total n^2 cell
if(level==k){
    ans++;
    //boards gives the solution where k knights has been placed
    return;
}
// choices
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(check(i,j)){
            //place
            board[i][j]=1;
            //move
            rec(level+1);
            //unplace
            board[i][j]=0;
        }
    }
}

}
void solve(){
    cin>>n>>k;
    rec(0);
    // here we are dividing the ans with k! because all knights are same // but we arranging like all knights are different
    for(int i=1;i<=k;i++) ans/=i;
    cout<<ans<<endl;
  
}
signed main(){
    solve();
}