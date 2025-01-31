#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
string s1,s2;
int dp[1001][1001];
int rec(int i,int j){
    // here dp(i,j) tell me about best lcs from s1[i....n-1] and s2[j....m-1]
    // purning

    //base case
    if(i>=n ||j>=m) return 0;

    //cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    //transition
    int ans=0;
    ans=max(ans,rec(i+1,j));
    ans=max(ans,rec(i,j+1)); 
    if(s1[i]==s2[j]){
        ans=max(ans,1+rec(i+1,j+1));
    }
    //save and return
    return dp[i][j]=ans;
}
void solve(){
   // cin>>n>>m;
    cin>>s1>>s2;
     n=s1.size();
     m=s2.size();
   
     if(n==0 || m==0){
        cout<<"0"<<endl;
        return;
     }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;



}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}