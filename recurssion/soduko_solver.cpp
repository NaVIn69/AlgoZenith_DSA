#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we have given sudoku grid , and i want to solve it
const int boardsize=4;
const int cellsize=2;
int board[4][4];
int ans=0;

bool check(int ch,int row,int col){
    // here first check for the row
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
void rec(int row,int col){
    // this fun tell me about can we place the some valid value at tha (row,col) -> this is cell where we place the value

    if(col==boardsize){
        // when we have been traversed all the choice of that row and now we have to move at the next row
        rec(row+1,0);
        return ;
    }
    if(row==boardsize){
        
        // base case 
        // here we have been travelled all the row means we have been all the cells of the board
        for(int i=0;i<boardsize;i++){
            for(int j=0;j<boardsize;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        ans++;
        return ;
    }
    // we have to check all the value we can place on that cell like (1 2 3 .... boardsize)
    // choice on that level
    if(board[row][col]==0){
    for(int ch=1;ch<=boardsize;ch++){
        // here we are checking on that level
    
        if(check(ch,row,col)){
            // move
            board[row][col]=ch;
            rec(row,col+1);
            board[row][col]=0;
        }
    }
  }else if(check(board[row][col],row,col)){
          rec(row,col+1);
    }



}
void solve(){
    for(int i=0;i<boardsize;i++){
        for(int j=0;j<boardsize;j++){
            cin>>board[i][j];
        }
    }
    // for(int i=0;i<boardsize;i++){
    //     for(int j=0;j<boardsize;j++){
    //         cout<<board[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    rec(0,0);
    cout<<ans<<endl;


}
signed main(){
    solve();
}