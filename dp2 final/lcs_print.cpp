#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
string s1,s2;
int n,m;
int dp[3005][3005];
int back[3005][3005];
// in the back[i][j] store the best operation what we have to do for getting 
int rec(int i,int j){
    // this function return the lcs from s1[i........n] and s2[j....m]

    if(i==n||j==m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    ans=max(ans,rec(i+1,j));
    ans=max(ans,rec(i,j+1));
    if(s1[i]==s2[j]){
        ans=max(ans,1+rec(i+1,j+1));
    }
    return dp[i][j]=ans;

}
string str="";
void generate(int i,int j){
   if(i>=n||j>=m){
    return ;
   }else{
    // here we hvae 4 condition
    if(s1[i]==s2[j]){
        cout<<s1[i];
        generate(i+1,j+1);
        return ;
    }
     int first_i=rec(i+1,j);
     int second_j=rec(i,j+1);
     if(first_i>second_j){
        // measn we are disacarding the ith char
        generate(i+1,j);

     }else{
        generate(i,j+1);
     }

   }
}
void solve(){
  cin>>s1>>s2;
  n=s1.size();
  m=s2.size();
  memset(dp,-1,sizeof(dp));
 int ans=rec(0,0);
  generate(0,0);
  cout<<str<<endl;
}
signed main(){
    solve();
}