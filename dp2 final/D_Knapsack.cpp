#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,w;
int weight[101];
int val[101];

// here we have to find the maximum value
int dp[101][100100];
int rec(int level,int wleft){
    // this function return me the maximum value selecting the element such that whose sum is less than equal to wleft
    if(level==n){
        return 0;
    } 

    //cacheing
    if(dp[level][wleft]!=-1){
        return dp[level][wleft];
    }

    // choice

    //dont take
    int ans=rec(level+1,wleft);

    // take
    if(wleft>=weight[level]){
        ans=max(ans,val[level]+rec(level+1,wleft-weight[level]));
    }
   dp[level][wleft]=ans;
    return ans;
}

void solve(){
    cin>>n>>w;
    for(int i=0;i<n;i++){
        cin>>weight[i]>>val[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,w)<<endl;

}
signed main(){
    solve();
}