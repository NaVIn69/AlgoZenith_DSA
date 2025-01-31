#include<bits/stdc++.h>
using namespace std;
#define int long long
#define  endl "\n"
int n,m;
int arr[1001][1001];
int done[1001][1001];
int dp[1001][1001];
int rec(int i,int j){
    // this function return me the maximum sum upto (i,j) including
    if(i<0||j<0){
        return -1e18;
    }
    // base case
    if(i==0&&j==0){
        return arr[i][j];
    }
    // cache check
    if(done[i][j]){
        return dp[i][j];
    }

    // compute
    int ans=arr[i][j]+max(rec(i-1,j),rec(i,j-1));

    done[i][j]=1;
    dp[i][j]=ans;
    return ans;
}
void solve(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>arr[i][j];
        done[i][j]=0;
    }
  }
  cout<<rec(n-1,m-1)<<endl;
}
signed main(){
    solve();
}