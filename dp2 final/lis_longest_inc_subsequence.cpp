#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[10010];
int dp[10010];
int rec(int i){
    // this fn give me lis ending at i
    //purning
    if(i<0) return 0;

    // base case

    // cache check
    if(dp[i]!=-1){
        return dp[i]; 
    }
    // compute
    // transition
    int ans=1;
    for(int prev_taken=0;prev_taken<i;prev_taken++){
        if(arr[prev_taken]<arr[i]){
            ans=max(ans,rec(prev_taken)+1);
        }
    }
    dp[i]=ans;
    return ans;
}
void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  memset(dp,-1,sizeof(dp));
  int best=0;
  for(int i=0;i<n;i++){
    best=max(best,rec(i));
  }
  cout<<best<<endl;

}
signed main(){
    solve();
}