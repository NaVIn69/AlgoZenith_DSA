#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
string s1,s2;
int n,m;
int dp[5050][5050];
int back[5050][5050];

int rec(int i,int j){
    // this fn return the lcs from s1[i.....n] and s2[j....m]
    if(i>=n||j>=m) return 0;

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    // here we are discarding the ith character of s1
    //0
    ans=max(ans,rec(i+1,j));
    int ith_char=rec(i+1,j);
    // here we are discarding the jth charachter of s2
    //1
    ans=max(ans,rec(i,j+1));
    int jth_char=rec(i,j+1);
    int eql_char=0;
    if(s1[i]==s2[j]){
        // here we are taking the both character and
        // then discarding the character
        ans=max(ans,1+rec(i+1,j+1));
        eql_char=rec(i+1,j+1);
        //2
        
    }
     if(ith_char>jth_char&&ith_char>eql_char){
        back[i][j]=0;
     }else{
        back[i][j]=1;
     }
     return dp[i][j]=ans;
    
}
void generate(int i,int j ){
    // here thi
    if(i>=n&&j>=m){
        return ;
    }
    int ch=back[i][j];
    if(ch==0){
        cout<<s2[j]<<" ";
        generate(i,j+1);
    }else if(ch==1){
        cout<<s1[i]<<" ";
        generate(i+1,j);
    }else if(ch==2){
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
//  cout<<str<<endl;


}
signed main(){
    solve();
}