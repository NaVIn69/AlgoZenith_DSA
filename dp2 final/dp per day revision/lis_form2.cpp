// in form 2 my state tells me about what is the best thing we can obtain from (0.....level)
/// form 2
// jumpy manner
// partition
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[10010];
int dp[10010];
int rec(int level){
    //best LIS ending at level
    if(level<0){
        return 0;
    }

    // base case

    //cache check
    if(dp[level]!=-1){
        return dp[level];
    }
    //compute
    int ans=1;
    for(int prev_taken=0;prev_taken<level;prev_taken++){
        if(arr[prev_taken]<arr[level]){
            ans=max(ans,1+rec(prev_taken));
        }
    }
    return dp[level]=ans;
} 
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
   int best=1;
   for(int i=0;i<n;i++){
    best=max(best,rec(i));
   }
   cout<<best<<endl;



}
signed main(){
    solve();
} 
