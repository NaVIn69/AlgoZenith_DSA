#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n;
int arr[100100];
int dp[100100];
int rec(int i){
    // dp(i) tells me about the maximum subarray sum upto ith index
    //base case
    if(i==0) return arr[0];

    //cache check
    if(dp[i]!=-1){
        return dp[i];
    }

    //transition
    dp[i]=max(rec(i-1)+arr[i],arr[i]);


    //save and return 
    return dp[i];
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int best=INT_MIN;
    memset(dp,-1,sizeof(dp)); 
    for(int i=0;i<n;i++){
        best=max(best,rec(i));
    }
    cout<<best<<endl;


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