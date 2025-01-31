// we have to find the minimum cost to cut that rod
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int x[1001];
int dp[1001][1001];
int rec(int l,int r){
    //purining

    //base case
    if(l+1==r){
        // means unit length ke rod to aur nhi cutt kr skte hai
        return 0;
    }
    //cache check
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    //transition
    // here we have to mimimize the cost cutiing of the rod
    int ans=1e9;
    for(int p=l+1;p<=r-1;p++){
        ans=min(ans,x[r]-x[l]+rec(l,p)+rec(p,r));
    }

    //save and return
    return dp[l][r]=ans;
}
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>x[i];
  }
  // minimum cost
  memset(dp,-1,sizeof(dp));
  cout<<rec(0,n)<<endl;

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