#include<bits/stdc++.h>
using namespace std;

int n,m;
string s1,s2;
int dp[1001][1001];
int back[1001][1001];

// it gives me diff length from (i....n-1) and (j...m-1)
int rec(int i,int j){
    // it give me optimal diff length means -> if some character is present in both the contribution is 0 otherwise contribution is 1
  if(i==n&&j==m) return 0;

  if(dp[i][j]!=-1) return dp[i][j];

  int ans=1e9;
  // here we have to delete the ith character from s1
  if(i<n){
    if(rec(i+1,j)+1<ans){
        ans=rec(i+1,j)+1;
        back[i][j]=0;
    }
  }
  // here we add the jth character from string s2                
  if(j<m){
    if(rec(i,j+1)+1<ans){
        ans=rec(i,j+1)+1;
        back[i][j]=1;
    }
  }
   
  // here  the ith and jth character are same in both string 
  if(i<n&&j<m&&s1[i]==s2[j]){
     if(rec(i+1,j+1)+1<ans){
        ans=rec(i+1,j+1)+1;// here both character is 
        back[i][j]=2;
     }
  }
  return dp[i][j]=ans;
}
int cnt=0;
void generate(int i,int j){
    if(i==n&&j==m){
        return ;
    }
    int ch=back[i][j];
    if(ch==0){
      cout<<"-"<<s1[i]<<" ";
      if(cnt>0)cnt--;
      else cnt++;
      generate(i+1,j);
    }else if(ch==1){
        cout<<"+"<<s2[j]<<" ";
        cnt++;
        generate(i,j+1);
    }else if(ch==2){
       
        cout<<" "<<s1[i]<<" ";
        generate(i+1,j+1);
    }
}
void solve(){

    cin>>s1>>s2;
    n=s1.size();
    m=s2.size();
    memset(dp,-1,sizeof(dp));
    int len=rec(0,0);
    cout<<len<<endl;
    generate(0,0);
    cout<<cnt<<endl;


}
int main(){
  solve();
}