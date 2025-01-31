#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n,m;
char arr[1001][1001];
int dp[10001][1001];
int rec(int i,int j){
    // dp(i,j) tell me about total path from (0,0) to (i,j)
    //purining
    if(i<0||j<0){
        return 0;
    }

    //base case
    if(i==0 && j==0) return 1;
    if(arr[i][j]=='#') return 0;

    // cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    //transition
    int ans=0;
    if(i!=0){
        ans=rec(i-1,j);
    }
    if(j!=0){
        ans=(ans%mod+rec(i,j-1)%mod)%mod;
    }
    

    //save and return
    return dp[i][j]=ans;
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    // if(arr[0][0]=='#' || arr[n-1][m-1]=='#'){
    //     cout<<"0"<<endl;
    //     return;
    // }
    memset(dp,-1,sizeof(dp));
    cout<<(rec(n-1,m-1)%mod+mod)%mod<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
}