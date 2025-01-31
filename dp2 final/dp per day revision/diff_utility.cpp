// here we have to find the common string from which we can generate the both string 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
string s1,s2;
int n,m;
int dp[1001][1001];
int back[1001][1001];
int rec(int i,int j){
    // this give the smallest diff string length in s1(i....n-1),s2(j,m-1);
    if(i==n&&j==m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    // compute
    int ans=1e9;
    if(i<n){
        // here we are discarding thr ith charactrer;
        // deleteing the ith character from string i
       if(rec(i+1,j)+1<ans){
        ans=rec(i+1,j)+1;
        back[i][j]=0;
        // 0th means discarding the ith character
       }
    }
    if(j<m){
        // here we are discarding the jth character
        // here we are discarding the jth character from  string s2
        if(rec(i,j+1)+1<ans){
            ans=rec(i,j+1)+1;
            back[i][j]=1;
            // discarding the jth char
        }
    }
    if(i<n&&j<m&&s1[i]==s2[j]){
        if(rec(i+1,j+1)+1<ans){
            ans=rec(i+1,j+1)+1;
            back[i][j]=2;
            // common character
        }
    }

    return dp[i][j]=ans;
    
}

void generate(int i,int j){
    if(i==n&&j==m) return ;
        int op=back[i][j];
        if(op==0){
           // discarding the ith char
           cout<<"-"<<s1[i]<<" ";
           generate(i+1,j);
        }else if(op==1){
            cout<<"+"<<s2[j]<<" ";
            generate(i,j+1);
        }else{
            cout<<s1[i]<<" ";
            generate(i+1,j+1);
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