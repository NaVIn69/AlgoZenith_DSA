#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
// we have shared array across the 
int queens[14];
// on every level we placed the queens
bool check(int row,int col){
    for(int pr=0;pr<row;pr++){
        int prcol=queens[pr];
        if( )

    }
}
int rec(int level){
    // this will give me the total number of ways to place the queens from (row,col) to (n-1,m-1);
    if(level==n){
        // we found the one way to place the n queens on board like they dont attack each other
        return 1;
    }
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