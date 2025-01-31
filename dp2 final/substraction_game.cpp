#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int dp[100100];
int rec(int x){
    // this tells me about from that given x can i win or loss by given condition
    if(x==0){
        return 0;
    }
    if(dp[x]!=-1){
        return dp[x];
    }
    int ans=0;
    // we assume that given state is lossing
    for(int m=0;(1<<m)<=x;m++){
        if(rec(x-(1<<m))==0){
            // if any of the state is lossing the i can win
            ans=1;
            break;
        }
    }

   return dp[x]=ans;
}
void solve(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<rec(n)<<endl;
    for(int i=0;i<=10;i++){
        cout<<rec(i)<<endl;
    }

}
signed main(){
    solve();
}
