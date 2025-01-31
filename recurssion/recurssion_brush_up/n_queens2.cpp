#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int queens[14];
int grid[14][14];
bool check(int row,int column){
   // here we have to check that can we place the queens at that place or not 
   // we go through all the previous config // state
   for(int pr=0;pr<row;pr++){
      int pc=queens[pr];
      if(pc==column|| abs(pr-row)==abs(pc-column)){
        return 0;
      }
   }
   return 1;
}
int rec(int level){
    // this recursive code tells about the total number of ways to place the queens form level to n from previous config
    if(level==n){
        // here we have been placed the one config of queens in the grid
        return 1;
    }
    // choice
    int ans=0;
    for(int ch=0;ch<n;ch++){
        if(check(level,ch)){
           queens[level]=ch;
           ans+=rec(level+1);
           queens[level]=-1;
        }
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