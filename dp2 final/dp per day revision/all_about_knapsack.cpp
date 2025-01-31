#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,w;
int weight[1001];
int val[1001];
int dp[101][1001];
vector<int>sol;
void generate(int i,int x){
    if(i==n){
        return;
    }else{
        int donttake=rec(i+1,x);
        int take=0;
        if(weight[i]<=x){
            take=rec(i+1,x-weight[i])+val[i];
        }
        if(donttake>take){
            generate(i+1,x);
        }else{
           sol.push_back(i);
           generate(i+1,x-weight[i]);
        }
    }
}

int rec(int level,int wleft){
// def -> this function return the maximum value from n where wleft is remaining

     //purning
     if(wleft<0){
        return -1e9;
     }

     // base case
     if(level==n){
        return 0;
     }

     // cache check
     if(dp[level][wleft]!=-1){
        return dp[level][wleft];
     }

      // transition
     // dont take
      int ans=rec(level+1,wleft);
      // take
      if(weight[level]<=wleft){
      ans=max(ans,val[level]+rec(level+1,wleft-weight[level]));
      }

      return dp[level][wleft]=ans;

     // save and return
}
void solve(){
  cin>>n>>w;
  for(int i=0;i<n;i++){
    cin>>weight[i];
  }
  for(int i=0;i<n;i++){
    cin>>val[i];
  }


}
signed main(){
    solve();
}