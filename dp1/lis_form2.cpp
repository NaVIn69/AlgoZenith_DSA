// dp(level) => it tells me about the best lis ending at index level
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];
int dp[100100];
int rec(int level){
    // best lis ending at level
    //purning

    // basecase
    if(level<0) return 0;

    // cache check
    if(dp[level]!=-1){
        return dp[level];
    }
    
    // transition
    int ans=1;
    for(int prev_taken=0;prev_taken<level;prev_taken++){
        // here we are checking if (arr[prev_taken]<arr[level] then it goes for next 
        if(arr[prev_taken]<arr[level]){
            ans=max(ans,1+rec(prev_taken));
        }
    }

    // save and return
     return dp[level]=ans;

}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    // final answer
   // int ans=rec(n-1);
    int best=0;
    for(int i=0;i<n;i++){
        best=max(best,rec(i));
        // here best tells me about best lis upto that index means (not complesary to including that last index)
        
    }
    // dp[i] => it tells me about the best lis ending at that index (means last index ko lena hi hai)
     cout<<best<<endl;




}
signed main(){
    solve();
}
 // tc o(n^2);