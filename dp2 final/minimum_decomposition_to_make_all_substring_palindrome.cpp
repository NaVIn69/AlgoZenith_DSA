#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
string s;
int check[1001][1001];
int dp[1001];
int back[1001];
// this back array store all the break points of the string
// here palindrome check is the zero based then we have to convert into the 1 based (l,...r) into the (l-1....r-1);
int check_palindrome(int l,int r){
    if(l>=r){
        return 1;
    }
    if(check[l][r]!=-1){
        return check[l][r];
    }
    int ans=0;
    if(s[l-1]==s[r-1]&&check_palindrome(l+1,r-1)){
        ans=1;
    }
    return check[l][r]=ans;

}

// rec(i) is the one based index dp on string
int rec(int i){
    // this return the minimum break point from (1....i) to make all the substring palindrome
    if(i==0){
        return -1;
    }
    // cache check
    if(dp[i]!=-1){
        return dp[i];
    }
    int ans=1e9;
    // here we are traversing for all the break points
   for(int j=0;j<i;j++){
    if(check_palindrome(j+1,i)){
        // if(rec(j)+1<ans){
        //     ans=rec(j)+1;
        // }
        ans=min(ans,rec(j)+1);
    }
   }
    return dp[i]=ans;
}
void generate(int i){
    if(i==0){
        return ;
    }
  
}
void solve(){
cin>>s;
n=s.size();
memset(dp,-1,sizeof(dp));
memset(check,-1,sizeof(check));
cout<<rec(n)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}