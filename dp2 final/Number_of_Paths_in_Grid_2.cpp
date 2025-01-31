#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n,m,k;
int arr[205][205];
int dp[205][205][205];
int rec(int i,int j,int kleft){
// fn def-> this give me the total number of ways to make from (i,j,kleft) to (n-1,m-1,0)
 // purining
 if(i>=n || j>=m ||kleft<0) return 0;

 // base case
 if(i==n-1&&j==m-1&&arr[i][j]!=1){
    return 1;
 }     
 if(i==n-1&&j==m-1&&arr[i][j]==1&&kleft>0){
    return 1;
 }
 if(arr[i][j]==1&&kleft==0){
    return 0;
 }
 // cache check
 if(dp[i][j][kleft]!=-1){
    return dp[i][j][kleft];
 }
 // transition compute
 int ans=0;

if(arr[i][j]==1&&kleft!=0){
    ans=(ans%mod+(rec(i+1,j,kleft-1)%mod+rec(i,j+1,kleft-1)%mod)%mod)%mod;
}else{
    ans=(ans%mod+(rec(i+1,j,kleft)%mod+rec(i,j+1,kleft)%mod)%mod)%mod;
}

 return dp[i][j][kleft]=ans;


}
void solve(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
           
        }
    }
     for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int z = 0; z <= k; z++)
            {
                dp[i][j][z] = -1;
            }
        }
    }
    cout<<rec(0,0,k)<<endl;
    
    


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}