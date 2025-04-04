#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n;
// here in 3*3 cell , we have to connect n cells ,and we have to find the total number of pattern which connects n cells
// on each cell we have to start , and find the total number of solution which connect n cells
// each pattern is going to repeat two times , 
// level is my start (row, col) ,
// choice is left ,right , top, bottom , we have to maintain a visited array which marks that cell is visited or not
// int vis[3][3];
// on each choice , we have to check that , that move is valid or not 
// if valid then move to the next choice(level)
// if(number of cells we have been visited n then we have been find the 1 solution from that starting point)
int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,-1,1,1,-1,1,-1};
int skip[10][10];
// this dx and dy containe the left,right, top bottom and diagonal and move  because we can move

// here we check all my valid move
bool is_valid(int row,int col,int nx,int ny){
    
}

// int rec(int level,int row,int col){
//   // this fn give me total number of ways to generate the pattern from (row,col) which connect n cells
//     if(level==n){
//         // here we can print the vis[9][9] , which contain only ones
//         // for(int i=0;i<3;i++){
//         //     for(int j=0;j<3;j++){
//         //         if(vis[i][j]==1){
//         //             cout<<"( "<<i<<" "<<j<<" ) "<<" ";
//         //         }
//         //     }
//         // }
//         // cout<<endl;
//         return 1;
//     }
//     // choice 
//     int ans=0;
//     // this ans give me total number of pattern we can generate the from (row,col) while moving in the direction of left, right top ,down
//     for(int i=0;i<8;i++){
//         int nx=row+dx[i];
//         int ny=col+dy[i];
//         // check 
//         if(nx>=0&&nx<3&&ny>=0&&ny<3&&(is_valid(row,col,nx,ny))){
//             // here we can move 
//             vis[nx][ny]=1;
//             ans+=rec(level+1,nx,ny);
//             // revert back
//             vis[nx][ny]=-1;

            
//         }
//     }
//     return ans;

// }

int vis[10];
// here we have current number and we have ,on which level i am at means we are tarversing on (1 to 9) digits and try to see ,can 
// we trverse or not
int rec2(int cur,int level){
   if(level==n) {
    return 1;
   }
   // choice 
   // here we mark that curr element as visited and explore all the choice of that value
   vis[cur]=1;

   int ans=0;
   for(int i=1;i<=9;i++){
       // first we see that 
        // if(cur==i) continue;
       // here we checking 

       if(!vis[i]&&(!skip[cur][i]||vis[skip[cur][i]])){
        // vis[i]=1;
        ans+=rec2(i,level+1);
        // vis[i]=0;
       }
   }

   vis[cur]=0;
   return ans;

}
void solve(){
    cin>>n;
    memset(vis,0,sizeof(vis));
    memset(skip,0,sizeof(skip));
    int ans=0;
    skip[1][3]=skip[3][1]=2;
    skip[1][7]=skip[7][1]=4;
    skip[3][9]=skip[9][3]=6;
    skip[2][8]=skip[8][2]=5;
    skip[7][9]=skip[9][7]=8;
    skip[1][9]=skip[9][1]=skip[7][3]=skip[3][7]=skip[4][6]=skip[6][4]=5;
    // here we see the symemtric 
    // when we start from the 1,3,7,9 then we get same number of pattern
    // when we satrt from the 2,4,6,8 then we get same number of pattern
    // when we start from 5 , then we get number of pattern
    ans+=rec2(1,1)*4;
    // memset(vis,0,sizeof(vis));
    // memset(skip,0,sizeof(skip));
    
    ans+=rec2(2,1)*4;
    // memset(vis,0,sizeof(vis));
    // memset(skip,0,sizeof(skip));
    ans+=rec2(5,1);
    cout<<ans<<endl;


}
signed main(){
    solve();
}