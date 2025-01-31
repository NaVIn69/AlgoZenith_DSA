#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int queens[15];
bool check(int row,int col){
    bool ans=false;
    for(int pr=0;pr<row;pr++){
        int pc=queens[pr];
        if(col==queens[pr]||abs(col-pc)==abs(pr-row)){
            return 0;
        }
    }
    return 1;
}

int rec(int level){
    if(level==n){
        // here we have been placed all the queens
        // here we find the one suitable state
        return 1;
    }
    // exploring all the choice all that level
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