#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int queens[14];
bool check(int level,int col){
    for(int pr=0;pr<level;pr++){
        int pc=queens[pr];
        if(pc==col||abs(pr-level)==abs(pc-col)){
            return 0;
        }
    }
    return 1;
}
int rec(int level){
    // this return the total number of ways to place the queens from (level....n-1) whenever we have been  placed the queens in (0....level)
    if(level==n){
        // means we have been placed the queens
        return 1;
    }
    int ans=0;
    // choice 
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
    cout<<rec(0)<<endl;

}
signed main(){
    solve();
}