#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n,k;
int arr[105];
int dp[101][100001];
int rec(int i,int left){
    // this return thr number of ways to distrubute the left candies from (i....n)
    //purining
   if(left==0) return 1;

    // base case
    if(i==n){
        // if(left==0){
        //     return 1;
        // }
        return 0;
    }
  if(left<0) return 0;

    // cache check
    if(dp[i][left]!=-1){
        return dp[i][left];
    }
    int ans=0;
    // transition
    for(int ch=0;ch<=k;ch++){
        int capacity=arr[i];
        if(ch<=arr[i]){
         ans=(ans%mod+rec(i+1,left-ch)%mod)%mod;
        }
    }

return dp[i][left]=ans;

    //save and return 
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<(rec(0,k)%mod+mod)%mod<<endl;
    


}
signed main(){
    solve();
}