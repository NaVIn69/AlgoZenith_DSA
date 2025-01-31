#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n,m;
string s1;
int dp[1001][1001];
int rec(int l,int r){
  // dp(l,r) gives longest palindromic subsequnce in between (l to r)
  //pruning
  if(l>r) return 0;

  //base case
  if(l==r) return 1;


  //cache check
  if(dp[l][r]!=-1){
    return dp[l][r];
  }

  //transition
  int ans=-1e9;
  if(s1[l]==s1[r]){
    ans=max(ans,2+rec(l+1,r-1));
  }else{
    ans=max(ans,max(rec(l+1,r),rec(l,r-1)));
  }

  //save and return
  return dp[l][r]=ans;
      
}
void solve(){
  
   cin>>s1;
   n=s1.size();
   memset(dp,-1,sizeof(dp));
   cout<<rec(0,n-1)<<endl; // it gives me longest palindromic subsequence i can make from that string
   //cout<<(n-rec(0,n-1))<<endl;

    
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