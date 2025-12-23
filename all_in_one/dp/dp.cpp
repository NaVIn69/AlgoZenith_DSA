#include<bits/stdc++.h>
using namespace std;

// find total number of ways to move on the nth stair using step 1,2 ,3
// here in the recursive something is going to repetative
int n;
int dp[100100];
int rec(int level){
    if(level==n){
        return 1;
    }
    if(dp[level]!=-1){
        return dp[level];
    }
    // choice 
    int ans=0;
    for(int step=1;step<=3;step++){
        if(level+step<=n){
            ans+=rec(level+step);
        }
    }
    dp[level]=ans;
    return ans;
}

void solve(){
    cin>>n;
    memeset(dp,-1,sizeof(dp));
}