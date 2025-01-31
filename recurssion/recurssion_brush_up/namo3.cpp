#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we have given the n*n chessboard
int n;
int queens[15];
// this queens array is my shared variable in the code
// here in dp code we keep the shared variable inside the recursive parameters

bool check(int row,int col){
   // we check on the previous state
    // we are placing on the 
    for(int pr=0;pr<row;pr++){
        int pc=queens[pr];
        if(pc==col || abs(pr-row)==abs(pc-col)){
            // some queens is placed in that way i cant placed the queens at (row,col)
            return 0;
        }
    }
    return 1;
}

int rec(int level){
    // here we have placed the queens (0........level-1) 
    // this function return the all counting from that level.......n which is my state
    if(level==n){
        // here we placed all the queens in the chess board and we find one state
        return 1;
    }
    // choices
    // on that level we have n choices (that is the column)
    int ans=0;
    for(int ch=0;ch<n;ch++){
        // check that my choice is valid or not
        if(check(level,ch)){
            // place the queens
            queens[level]=ch;
            // call the recursive call 
            // that recursive call give me all the answer
        ans+=rec(level+1);
        queens[level]=-1;
        }
    }
    return ans;
}
void solve(){
    cin>>n;
    memset(queens,-1,sizeof(queens));
    // believe in ur function defination
    cout<<rec(0)<<endl;

}
signed main(){
    solve();
}