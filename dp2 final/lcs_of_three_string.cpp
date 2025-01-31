#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define endl "\n"
int n,m,t;
string s1,s2,s3;
int dp[105][105][105];
int rec(int i,int j,int k){
// def -> this function return the maximum common subsequence from s1(0...i),s2(0....j),s3(0.....k)
if(i<0||j<0||k<0){
    return 0;
}
// base case 
  if(i==0&&j==0&&k==0){
    if(s1[i]==s2[j]&&s2[j]==s3[k]){
        return 1;
    }
    return 0;
  }

  // cache check
   if(dp[i][j][k]!=-1){
    return dp[i][j][k];
   }
   // transition
   int ans=0;
   ans=max(ans,rec(i-1,j,k));
   ans=max(ans,rec(i,j-1,k));
   ans=max(ans,rec(i,j,k-1));
   if(s1[i]==s2[j]&&s2[j]==s3[k]){
     ans=max(ans, 1+rec(i-1,j-1,k-1));
   }


    return dp[i][j][k]=ans;

}
void solve(){
  cin>>s1>>s2>>s3;
    //   cout<<s1<<" "<<s2<<" "<<s3<<endl;
  n=s1.size();
  m=s2.size();
  t=s3.size();
  memset(dp,-1,sizeof(dp));
//   cout<<s1<<" "<<s2<<" "<<s3<<endl;
  cout<<rec(n-1,m-1,t-1)<<endl;


}
int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}