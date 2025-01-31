// string s
// query q
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
string s;
int n;
int dp[1005][1005];
int rec(int l,int r){
     if(l>=r){
        return 1;
     }
     if(dp[l][r]!=-1){
        return dp[l][r];
     }
     int ans=0;
     if(s[l]==s[r]&&rec(l+1,r-1))ans=1;
     return dp[l][r]=ans;
}
void solve(){
  cin>>s;
  n=s.size();
  memset(dp,-1,sizeof(dp));
  rec(0,n-1);

  int q;
  cin>>q;
  while(q--){
    int l,r;
    cin>>l>>r;
    if(rec(l,r)){
        cout<<"palindrome"<<endl;
    }else{
        cout<<"not palindrome"<<endl;
    }

  }
}
signed main(){
    solve();
}