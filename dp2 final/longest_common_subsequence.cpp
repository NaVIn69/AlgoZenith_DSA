#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
string s1,s2;
int dp[1005][1005];
int rec(int i,int j){
// def -> this fn return the longest common subsequence upto i the index in s1 and upto jth index in s2
// purning
  if(i<0||j<0){
    return 0;
  }

  // base case
  if(i==0&&j==0){
    if(s1[i]==s2[j]){
        return 1;
    }else{
        return 0;
    }
  }


  // cache check
  // this return maximum common subsequence upto ith index and jth index
  if(dp[i][j]!=-1){
    return dp[i][j];
  }

  // transition
  // choice
  int ans=0;
  if(s1[i]==s2[j]){
    ans+=(1+rec(i-1,j-1));
  }else{
    ans+=max(rec(i-1,j),rec(i,j-1));
  }
  

  // save and return
  return dp[i][j]=ans;



}

// here we have to generate the solution
// longest common subsequence of two string
string str="";
void generate(int i,int j){
    if(i==0&&j==0) return;

    if(s1[i]==s2[j]){
        str+=s1[i];
        generate(i-1,j-1);
    }else{
        if(rec(i-1,j)<rec(i,j-1)){
            str+=s1[i];
            generate(i,j-1);
        }else{
            // here we discarding the 
            str+=s1[j];
            generate(i-1,j);
        }

    }


}
void solve(){
  cin>>s1>>s2;
  n=s1.size();
  m=s2.size();
  memset(dp,-1,sizeof(dp));
  cout<<rec(n-1,m-1)<<endl;
  generate(n-1,m-1);
  cout<<str<<endl;

}
signed main(){
    solve();
}