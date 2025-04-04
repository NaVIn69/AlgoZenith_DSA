#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int queens[10];
// this array is shared across all the recurssion and  this tell me state of the board
// where i have been placed the queens
bool check(int col,int row){
    for(int pr=0;pr<row;pr++){
        int pc=queens[pr];
         if(queens[pr]==col || abs(pr-row)==abs(pc-col)){
            return false;
         }
    }
    return true;
}
int rec(int level){
    // here we have been  decided the state of the queens from (0 to level-1);
    // now this fn give me total number of way to place the queen from (level to n-1);
    if(level==n){
        // mens we have been placed all the queens on the board;
        for(int i=0;i<n;i++){
            cout<<queens[i]<<" ";
        } 
        return 1;
    }
    int ans=0;
    /// choice  where we can place the n queens
    for(int ch=0;ch<n;ch++){
        // check , can we place the queens
        if(check(ch,level)){
            //place the queens 
            queens[level]=ch;
            // recursive move
            // this recursive give me total number of possible combination of placeing n queens from (level+1,n-1); 
            ans+=rec(level+1);

        }
        queens[level]=-1;
        // unplace and move to the next choice of the grid
    }
    return ans;
}
void solve(){
    cin>>n;
    memset(queens,-1,sizeof(queens));
    cout<<rec(0)<<endl;

}
signed main(){
    solve();
}