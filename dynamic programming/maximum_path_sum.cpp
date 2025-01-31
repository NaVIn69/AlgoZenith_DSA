#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<vector<int>>dp;
int arr[1000][1000];
int n,m;
int rec(int i,int j){
    //base case
    if(i>=n||j>=m) return -1e9;
    if(i==n-1&&j==m-1) return arr[i][j];
     
    //check
    if(dp[i][j]!=-1) return dp[i][j];

    //transition
    dp[i][j]=max(rec(i+1,j),rec(i,j+1))+arr[i][j];

    return dp[i][j];
}
void solve(){
 cin>>n>>m;

 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>arr[i][j];
    }
 }
 dp.resize(n+1,vector<int>(m+1,-1));
 int ans=rec(0,0);
 cout<<dp[0][0]<<endl;

}
signed main(){
    solve();
}