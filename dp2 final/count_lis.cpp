#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[10010];
int dp[10010];
int rec(int level){
    // this return the lis length followed by that element
    if(level<0){
        return 0;
    }
    // cache check
    if(dp[level]!=-1){
        return dp[level];
    }
    // transition
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
    int best=0;
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        best=max(best,rec(i));
        mpp[rec(i)]++;
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    int ans=1;
    for(auto v:mpp){
        ans=ans*v.second;
    }
    
    cout<<ans<<endl;


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