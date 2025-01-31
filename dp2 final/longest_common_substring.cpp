#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
string s1,s2;
int n,m;
int dp[1005][1005];
int rec(int i,int j){
    // this return the longest common substring from (i,j) to (n-1,m-1)
    if(i==n || j==m){
        return 0;
    }
    // cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    // transition
    int ans=0;
    if(s1[i]==s2[j]){
        // from here a new substring can start
        // previous substring jo chal rha hai usme 1 add kr do
       ans=max(ans,1+rec(i+1,j+1));
    }
    rec(i+1,j);
    rec(i,j+1);
   return dp[i][j]=ans;

    // save and return

}
void solve(){
  cin>>s1>>s2;
  n=s1.size();
  m=s2.size();
  memset(dp,-1,sizeof(dp));
 int best=0;
 // for every pair we find out which pair gives u the best longest substring
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        best=max(best,rec(i,j));
    }
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