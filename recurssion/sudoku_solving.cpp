#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int boardsize=4;
const int cellsize=2;
int board[boardsize][boardsize];
bool check(int ch,int row,int col){
     //check the row
     for(int c=0;c<boardsize;c++){
        if(c!=col && board[row][c]==ch) return false;
     }
    

     // check the column
     for(int r=0;r<boardsize;r++){
        if(r!=row && board[r][col]==ch) return false;
     }


     // check the square
     // we have to check in the cellsize matrix 
     int nr=(row/cellsize)*cellsize;
     int nc=(col/cellsize)*cellsize;
     for(int r=0;r<cellsize;r++){
        for(int c=0;c<cellsize;c++){
            if(nr+r==row&&nc+c==col) continue;

            if(board[nr+r][nc+c]==ch) return false;
        }
     }
     return true;
}
int ans=0;
void rec(int row,int col){
    if(col==boardsize){
        rec(row+1,0);
        return ;
    }
    // base case
    if(row==boardsize){
        //print board
        ans++;
        for(int i=0;i<boardsize;i++){
            for(int j=0;j<boardsize;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    //choice
    // here we have to check every cell that we place that element or not
    if(board[row][col]==0){
      // here choice is to place the value (1 to 4) on that row col 
    for(int ch=1;ch<=boardsize;ch++){
        if(check(ch,row,col)){
            //place
           board[row][col]=ch;
           //move
           rec(row,col+1);
           //unplace
           board[row][col]=0;
        }
    }
    }else{
        //prefilled
        if(check(board[row][col],row,col)){
            rec(row,col+1);
        }
    }

}
void solve(){
    for(int i=0;i<boardsize;i++){
        for(int j=0;j<boardsize;j++){
            cin>>board[i][j];
        }
    }
    rec(0,0);
    cout<<ans<<endl;

}
signed main(){
    solve();
}