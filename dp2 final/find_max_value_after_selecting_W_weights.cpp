// here we have given the weight array and val array 
// here we have to select the w weight and selecting w weight find the maximum value you can find
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int weight[1001];
int val[1001];
int dp[3000][3000];
int w;
int rec(int level,int wleft){
    // this recurance give me the max value we can obtain from wleft from that level
    // purning 

    //base case
    // here we have been traversed all the element   
    if(level==n){
       return 0;
    }

// cacheing
    if(dp[level][wleft]!=-1){
        return dp[level][wleft];
    }
    // transition
   // choice
   // dont take it#
   int ans=rec(level+1,wleft);
   //  take it
   if(weight[level]<=wleft){
    ans=max(ans,val[level]+rec(level+1,wleft-weight[level]));
   }

   dp[level][wleft]=ans;
   return ans;
}
void solve(){
  cin>>n>>w;
  for(int i=0;i<n;i++){
    cin>>weight[i];
  }
  for(int i=0;i<n;i++){
    cin>>val[i];
  }
memset(dp,-1,sizeof(dp));
int ans=rec(0,w);

}
signed main(){
    solve();
}