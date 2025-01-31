#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int a[100100];
int dp[105][100100];
int rec(int level,int left){
    //purining
    if(left<0){
        return 0;
    }
    // basecase
    if(level==n){
        if(left==0){
            return 1;
        }else{
            return 0;
        }
    }
    // cache check
    if(dp[level][left]!=-1){
        return dp[level][left];
    }
    // transition
    int ans=0;
    // dont take
    if(rec(level+1,left)==1){
        // means without taking that element we got my answer
        ans=1;
    }else if(rec(level+1,left-a[level])==1){ // here we are taking that element
        ans=1;
    }

    // save and return
    return dp[level][left]=ans;

}
void printset(int level,int left){
    // basecase
    // cout<<"printer :"<<" "<<level<<" "<<left<<endl;
    if(level==n){
        return ;

    }
    //
     if(rec(level+1,left)==1){
        // means without taking that element we got my answer
      printset(level+1,left);
    }else if(rec(level+1,left-a[level])==1){ // here we are taking that element
    cout<<a[level]<<" ";
       printset(level+1,left-a[level]);
    }
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
        int t;
        cin>>t;
        if(rec(0,t)){
            printset(0,t);
            cout<<endl;
        }else{
            cout<<"NO solution"<<endl;
        }
    }

}
signed main(){
    solve();
}