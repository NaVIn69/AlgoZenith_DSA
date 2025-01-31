// given grid find the path which go from top left to bottom right find maximum sum path 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
 int inf=1e9;
vector<vector<int>>arr;
vector<vector<int>>dp;
vector<vector<bool>>is;
int n,m;
// is tells me about that state is computed or not
int solve1(int i,int j){
    // bottom right corner
    if(i==n-1&& j==m-1){
        return arr[i][j];
    }
    // out of grid pr -infinty
    if(i>=n || j>=m) return -inf;
   

    // memomization
    if(is[i][j]){
        // already computed
        return dp[i][j];
    }
    // transition
  dp[i][j]=arr[i][j]+max(solve1(i,j+1),solve1(i+1,j));
  is[i][j]=true;
  return dp[i][j];
}
void solve(){
    cin>>n>>m;
    is.resize(n,vector<bool>(m,false));
    arr.resize(n,vector<int>(m));
    dp.resize(n+1,vector<int>(m+1,0));
   // is.resize(n+1,vector<bool>(m+1,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<solve1(0,0)<<endl;
   


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}