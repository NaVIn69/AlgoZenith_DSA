// print all the subset sum equal to target
// here we written that code that depends on the t means target

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,t;
int a[100100];
// write a recursive code which tells me about that array gives me sum==t or not
int dp[105][10100];
int rec(int level,int left){
    // we are at level now we have two choice take or dont take
    // purning
    if(left<0) return 0;
    // base case
    if(level==n){
        if(left==0){
            return 1;
        }else{
            return 0;
        }
    }

    // chache check
    if(dp[level][left]!=-1){
        return dp[level][left];
    }

    // transition
    int ans=0;
    // dont take 
    // here we are checking that without taking that element if we got that target then ans=1
    if(rec(level+1,left)==1){
        ans=1;
    }else if(rec(level+1,left-a[level])==1){
        // take
        // here we are taking that element and do checking     if we get that target then it return 1
        ans=1; 
    }
   // save and return
   return dp[level][left]=ans;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    int q;
    cin>>q;
    memset(dp,-1,sizeof(dp));
    while(q--){
        cin>>t;
    cout<<rec(0,t)<<endl;
    }


}
signed main(){
    solve();
}