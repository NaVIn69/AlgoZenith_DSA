#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we have to place n queens in each row , where 
int n;
// this queens is shared across the recursion ,and and here we store the queens position , where we have been placed this queens

int queens[15];
int dx[]={1,2,2,1-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};
bool check(int row, int col){
    // first check for queens
    for(int pr=0;pr<row;pr++){
        int pc=queens[pr];
        if((pc==col) || (abs(pr-row)==abs(pc-col))||abs(row-pr)*abs(col-pc)==2){
             return 0;
        }
    }
  
    // checking for knight position
      
 
    return 1;
}
int rec(int level){
    // this function tells me about that we have been placed the queens from (0.. level-1) and 
    // it give me total number of ways to place the queens from (level to n-1);
    if(level==n){
       
        return 1;
        // here we have been placed the n queens on the chess board
    }
    int ans=0;
    // choice on that level
    for(int ch=0;ch<n;ch++){
        // check
        if(check(level,ch)){
            // place the queens 
            queens[level]=ch;
            // move to the next level
           ans+=rec(level+1);
            // revert back and unplace
            queens[level]=-1;

        }
    }
    return ans;
    

}

void solve(){
 cin>>n;
 memset(queens,-1,n);

cout<<rec(0)<<endl;

}
signed main(){
    solve();
}