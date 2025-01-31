#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
string s1,s2;
int n,m;
int dp[1001][1001];
int rec(int i,int j){
    // this give me the longest common subsequence from (i......n) and (j.....m)
    if(i==n||j==m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    if(s1[i]==s2[j]){
        ans=max(ans,1+rec(i+1,j+1));
    }else{
        ans=max(ans,rec(i+1,j));
        ans=max(ans,rec(i,j+1));
}
return dp[i][j]=ans;

}
void generate(int i,int j){
    if(i==n||j==m){
        return ;
    }else{
        if(s1[i]==s2[j]){
            cout<<s1[i]<<" ";
            generate(i+1,j+1);
             
        }else{
           int ans1=rec(i+1,j);
           int ans2=rec(i,j+1);
           if(ans1>ans2){
            // here we are discarding the 
            generate(i+1,j);
           }else{
            generate(i,j+1);
           }
        }
    }
}
void solve(){
  cin>>s1>>s2;
  n=s1.size();
  m=s2.size();
  memset(dp,-1,sizeof(dp));
  cout<<rec(0,0)<<endl;
  generate(0,0);

}
signed main(){
    solve();
}