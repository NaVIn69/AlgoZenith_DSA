#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int dp[1000001];
int rec(int x){
    //base case
    if(x==0){
        return 0;
    }

    // chache check
    if(dp[x]!=-1){
        return dp[x];
    }

    //transition
    int ans=0;
    for(int m=0;(1<<m)<=x;m++){
        //here we are trying all possible solution to like
        // (x-2^0)
        //(x-2^1)  (x-2^2)...........(x-2^m)
        // after trying all possible solution if we find any lossing position of the oppenent the i can win
        if(rec(x-(1<<m))==0){
            ans=1;
            break;
        }

    }

    //save and return
    return dp[x]=ans;
}
void solve(){
   cin>>n;
//    memset(dp,-1,sizeof(dp));
//    // by using this loop we find the pattern and then solve the problem in o(1)
//    for(int i=0;i<=100;i++){
//     cout<<i<<":"<<rec(i)<<endl;
//    }
if(n%3==0){
    cout<<"Abhishek"<<endl;
}else{
    cout<<"Vivek"<<endl;
}
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}