#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int boardsize=4;
const int cellsize=2;
int board[boardsize][boardsize];
int takenrow[boardsize];
int takencol[boardsize];
int takengrid[cellsize][cellsize];
int log2arr[10010];
// get choice
// here we find which number we can place at that (row,col) 
int getchoice(int row,int col){
    // here we find which number is present in that row and column and grid by or operation
    int taken=(takenrow[row]|takencol[col]|takengrid[row/cellsize][col/cellsize]);
    // set bit "positon" of that "taken" number tells me about which number is present in that row and column and grid
    int nottaken=((1<<(boardsize+1))-1)^taken;
    // not taken number ka set bit tell me about which number is remaing 
    // taken ka bit          01110
    //(1<<(boardsize+1)-1) = 11111 
                   // xor  = 10001
   //here 0th bit index ka kuch important nhi hai
   // we have 4th position
   //unseting the 0th bit
   if(nottaken&1) nottaken^=1;
   return nottaken;
}

// here we are placing the ch value on that row and column
void makemove(int ch,int row,int col){
    board[row][col]=ch;
    // after placing that value we have to update the takenrow takencol array and alsoo the grid
    // set the ch index of that row value
    takenrow[row]^=(1<<ch);
    takencol[col]^=(1<<ch);
    takengrid[row/cellsize][col/cellsize]^=(1<<ch);
}
void revertmove(int ch,int row,int col){
    board[row][col]=0;
    takenrow[row]^=(1<<ch);
    takencol[col]^=(1<<ch);
   takengrid[row/cellsize][col/cellsize]^=(1<<ch);
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
      int chmask=getchoice(row,col);
     while(chmask){
        // chmask =         01110
       //chmask&(chmask-1)  01100       right most set bit ko unset kkr deta hai
                // xor      00010
        int last1=chmask^(chmask&(chmask-1));
        //inthe last1 rightmost bit is only se
        int last1pos=log2arr[last1];
        makemove(last1pos,row,col);
        rec(row,col+1);
        revertmove(last1pos,row,col);
        chmask=chmask&(chmask-1);
     }
        
    }
    else{
        // if value is the prefilled intailly we have make that masking of that
       
            rec(row,col+1);
    }

}
void solve(){
    for(int i=1;i<=9;i++){
        log2arr[1<<i]=i;
    }
    for(int i=0;i<boardsize;i++){
        for(int j=0;j<boardsize;j++){
          int ch;
          cin>>ch;
          makemove(ch,i,j);
            // cin>>board[i][j];
            // int k=board[i][j];
            // makemove(k,i,j);
        }
    }
    
    rec(0,0);
    cout<<ans<<endl;

}
signed main(){
    solve();
}