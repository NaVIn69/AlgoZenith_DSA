#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n;
int queen[100];
bool check(int row,int column){
    // check if we can placed the queen without getting attack
    for(int pr=0;pr<row;pr++){
        int pc=queen[pr];
        // (pr,pc ) has queen check if it attack (row ,queen)
        if(pc==column||abs(row-pr)==abs(column-pc)){

          return 0;
        }
    }
    return 1;

}
int rec(int level){ // here level is row
// given that you have decided [0--level-1] in queen
//explore all the possible solution by deciding [level.. n-1]
//count them 
// lccm
    //base case
    if(level==n){
        return 1;
    }
    // recursive case
    int ans=0;
    for(int ch=0;ch<n;ch++){
        // go through all the columns
        if(check(level,ch)){
            //place queen
            queen[level]=ch;
            // move
            // go into recursion into the next level
            ans+=rec(level+1);
            //unplace the queen
            queen[level]=-1;
        }
    }
    return ans;
}
void solve(){
  cin>>n;
  memset(queen,-1,sizeof(queen));
  cout<<rec(0)<<endl;


  
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}