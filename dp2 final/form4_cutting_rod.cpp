// here we have to cut the rod in such way
// the cost of cutting of rod should be minimum
// cost of cutting the rod is length of rod
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int x[1000];
int dp[1005][1005];
int rec(int l,int r){
    // this return the minicost to  cut the rod from [l.....r];
    // it return thr minimum cut 
    if(l+1==r){
        // here means we cant cut the rod of unit length
        return 0;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    int ans=1e9;
    for(int i=l+1;i<=r-1;i++){
        // here x[r]-x[l] is the cost of cutting the rod
        // here we are going through all the cutting point
        ans=min(ans,x[r]-x[l]+rec(l,i)+rec(i,r));
    }
    return dp[l][r]=ans;


}
void solve(){
 cin>>n;
 for(int i=1;i<=n;i++){
    cin>>x[i];
 }
 x[0]=0;
 memset(dp,-1,sizeof(dp));
 cout<<rec(1,n)<<endl;


}
signed main(){
    solve();
}