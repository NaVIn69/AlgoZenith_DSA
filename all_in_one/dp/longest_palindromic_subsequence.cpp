#include<bits/stdc++.h>
using namespace std;

int n;
string s1;
int dp[1001][1001];
int rec(int i,int j){
  // this gives me the longest palindromic subsequence between i.....j
  if(i>j){
    return 0;
  }
  if(i==j){
    return 1;
  }
  if(dp[i][j]!=-1){
    return dp[i][j];
  }
  int ans=0;
  if(s1[i]==s1[j]){
     ans=max(ans,2+rec(i+1,j-1));
  }else{
      ans=max(ans,rec(i+1,j));// discarding ith character
      ans=max(ans,rec(i,j-1));// discarding jth character
  }
  return dp[i][j]=ans;
}

string ans="";
void generate(int i,int j){
    if(i>j){
        return ;
    }
    if(i==j){
        ans[i]=s1[i];
        ans[j]=s1[j];
        return ;
    }
    if(s1[i]==s1[j]){
        ans[i]=s1[i];
        ans[j]=s1[j];
        generate(i+1,j-1);
        return;
    }else{
        int len1=rec(i+1,j);
        int len2=rec(i,j-1);
        if(len1>len2){
            generate(i+1,j);
        }else{
            generate(i,j-1);
        }
    }
}
void solve(){
    cin>>s1;
    n=s1.size();
    memset(dp,-1,sizeof(dp));
    int len=rec(0,n-1);
    cout<<len<<endl;
    ans.resize(len+4);
    generate(0,n-1);
    cout<<ans<<endl;

}
int main(){
    solve();
}