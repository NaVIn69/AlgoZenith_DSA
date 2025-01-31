#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
string s1,s2;
int n,m;
int dp[1005][1005];
int back[1005][1005];
int rec(int i,int j){
    // this function return the minimum length of diff string from s1[i....n] and s2[j...m]
    if(i==n&&
    j==m){
        // we traverse all the character
        return 0;
    }
    // cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    // transition
    int ans=1e9;
    // here we are discarding the ith character in the s1
    // 0 -> ith char in s1 discard
    if(i<n){
    if(rec(i+1,j)<ans){
        ans=rec(i+1,j)+1;
        back[i][j]=0;
    }
    }
    if(j<m){
        if(rec(i,j+1)<ans){
            // here we are discarding the jth character
            ans=rec(i,j+1)+1;
            back[i][j]=1;
        }
    }
    if(i<n&&j<m&&s1[i]==s2[j]){
        ans=rec(i+1,j+1)+1;
        // discarding the both character
        back[i][j]=2;
    }

    return dp[i][j]=ans;

}
string str="";
void generate(int i,int j){
    if(i==n&&j==m){
        return ;
    }
    int ch=back[i][j];
    if(ch==0){
      str+=s1[i];
      generate(i+1,j);
    }else if(ch==1){
        str+=s2[j];
        generate(i,j+1);
    }else if(ch==2){
       str+=s1[i];
       generate(i+1,j+1);
    }
}
void solve(){
  cin>>s1>>s2;
  n=s1.size();
  m=s2.size();
  memset(dp,-1,sizeof(dp));
//   cout<<rec(0,0)<<endl;
  generate(0,0);
  cout<<str<<endl;
}
signed main(){
    solve();
}