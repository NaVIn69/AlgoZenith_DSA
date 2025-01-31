// when we have three string and we have to find the lcs of that three string
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n,m,x;
string s1,s2,s3;
int dp[101][101][101];
int rec(int i,int j,int k){
    //purining

    //base case
    if(i>=n ||j>=m ||k>=x){
        return 0;
    }

    //cache check
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }

    //transition
    int ans=0;
    ans=max(ans,rec(i+1,j,k));
    ans=max(ans,rec(i,j+1,k));
    ans=max(ans,rec(i,j,k+1));
    if(s1[i]==s2[j]&&s2[j]==s3[k]){
        ans=max(ans,1+rec(i+1,j+1,k+1));
    }
    //save and return
    return dp[i][j][k]=ans;

}
void solve(){
    // cin>>n>>m>>x;
    cin>>s1>>s2>>s3;
    n=s1.size();
    m=s2.size();
    x=s3.size();
   memset(dp,-1,sizeof(dp));
   cout<<rec(0,0,0)<<endl;


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