#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
int arr[1000][1000];
int dp[1005][1005];
int done[1002][1002];
int rec(int i,int j){
    // this function gives me the maximum sum from (i,j) to the (n-1,m-1)
    //purning
    if(i>=n || j>=m){
        return -1e18;
    }

    // base case
    if(i==n-1&&j==m-1){
        return arr[i][j];
    }
    // cache check
    if(done[i][j]){
        return dp[i][j];
    }

    // transition
    int ans=arr[i][j]+max(rec(i+1,j),rec(i,j+1));
     done[i][j]=1;
    return dp[i][j]=ans;

}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            done[i][j]=0;
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;

   
}
signed main(){
    solve();
}