#include<bits/stdc++.h>
using namespace std;

int n,m;
string s1,s2;
int dp[1001][1001];
int rec(int i,int j){
    // it gives me longest subsequence ending at i in s1 and j in s2
    if(i<0||j<0){
        return  0;
    }
    if(i==0&&j==0){
        if(s1[0]==s2[0]){
            return 1;
        }
        return 0;
    }
    int ans=0;
    ans=max(ans,rec(i-1,j));
    ans=max(ans,rec(i,j-1));
    if(s1[i]==s2[j]){
        ans=max(ans,1+rec(i-1,j-1));
    }
    return dp[i][j]=ans;
}
string ans="";
void generate(int i,int j){
   if(i<0||j<0){
    return;
   }
   if(s1[i]==s2[j]){
    ans+=s1[i];
    generate(i-1,j-1);
    return ;
   }
   int len1=rec(i-1,j);// here we are disacrding the ith charcter of s1
   int len2=rec(i,j-1);
   if(len1>len2){
    generate(i-1,j);
   }else{
    generate(i,j-1);
   }
}

void solve(){
   cin>>s1>>s2;
   n=s1.size();
   m=s2.size();
   memset(dp,-1,sizeof(dp));
   cout<<rec(n-1,m-1)<<endl;
   generate(n-1,m-1);
   reverse(ans.begin(),ans.end());
   cout<<ans<<endl;
}
int main(){
    solve();
}