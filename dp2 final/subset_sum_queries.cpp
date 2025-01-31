#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,q;
int arr[101];
// here we have given a queries we have to find 
int dp[105][100100];
int rec(int level,int sum_left){
// def => this function return the can we form sum_left from that level to n-1
      // purning
        if(sum_left<0){
          return 0;
        }
      // base case
      if(level==n){
           if(sum_left==0){
            return 1;
           }
           return 0;
      }

      // cache check
      if(dp[level][sum_left]!=-1){
        return dp[level][sum_left];
      }

      // transition
      // can we create sum_left from level to n-1 element
      int ans=rec(level+1,sum_left)|rec(level+1,sum_left-arr[level]);

      // save and return
   return  dp[level][sum_left]=ans;

}
void solve(){
  cin>>n>>q;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  memset(dp,-1,sizeof(dp));
  while(q--){
    int sum;
    cin>>sum;
    int val=rec(0,sum);
    if(val==0){
      cout<<"-1"<<endl;
    }else{
      cout<<"1"<<endl;
    }

    // we have to find that can we obtain that sum
  }
}
signed main(){
    solve();
}