// ending at i
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n ;
int arr[10010];
int dp[10010];
int rec(int level){
    // this return the max lis length from(0...level) (inclusive)
    if(level<0){
        return 0;
    }
    // cache check
    if(dp[level]!=-1){
        return dp[level];
    }
    // transition
    int ans=1;
    for(int prev_taken=0;prev_taken<n;prev_taken++){
        if(arr[prev_taken]<arr[level]){
            ans=max(ans,1+rec(prev_taken));
        }
    }

}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


}
signed main(){
    solve();
}