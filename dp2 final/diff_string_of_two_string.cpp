// here we have given two string x and y
// here we to find the length of diff string
// first string =AATU
// second string =ATUA
// here multiple diff string we can be possible
// here diff String = A -A T U +A
// rec(i,j) return the length of diff string
// we also generate(i,j) print one of the diff string

// from diff string we can find how many character we have to delete for the first string to make equal to second string
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
string s1,s2;
int dp[5050][5050];
int back[5050][5050];
// this back array store for every state which operation is optimal from that state 
// here i denotes the ith in the string s1
// j denotes the jth in string s2
int rec(int i,int j){
    // this function return the length of diff string from s1[i.....n-1] and s2[j......m];
    // pruning

    //base case
    if(i==n&&j==m) return 0;


    // cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    // transition
    // here we have three state for transition
    // first delete the ith character from s1 
    int ans=1e9;
    if(i<n){
        // we are deleting the ith char and increase the length of string by 1
       if(rec(i+1,j)+1<ans){
        ans=rec(i+1,j)+1;
        back[i][j]=0;
       }
    }
    if(j<m){
      // we adding this character to the diff string
      if(rec(i,j+1)+1<ans){
        ans=rec(i,j+1)+1;
        back[i][j]=1;
      }
    }

    // if both character is equal 
    // there we adding the without sign 
// means this character is present in the both string
    if(i<n&&j<m&&s1[i]==s2[j]){
        if(rec(i+1,j+1)+1<ans){
            ans=rec(i+1,j+1)+1;
            back[i][j]=2;
        }
    }


    // save and return
    return dp[i][j]=ans;

}

// for generating the one of the Diff string
void generate(int i,int j ){
    // here thi
    if(i==n&&j==m){
        return ;
    }
    int ch=back[i][j];
    if(ch==0){
        cout<<"-"<<s1[i]<<" ";
        generate(i+1,j);
    }else if(ch==1){
        cout<<'+'<<s2[j]<<" ";
        generate(i,j+1);
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


}
signed main(){
    solve();
}