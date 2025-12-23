#include<bits/stdc++.h>
using namespace std;
// #define int long long
// #define endl "\n"

int n;
vector<vector<int>>arr;
int dp[100100][4];
//0->a ,b->1 ,c->2
// fn-> this will give me the maximum happines from level to n
int rec(int level,int prev){
    if(level==n){
        return 0;
    }
    if(dp[level][prev]!=-1){
        return dp[level][prev];
    }
    // choice 
    int ans=0;
    for(int i=0;i<3;i++){
       if(i!=prev||level==0){
      ans=max(ans,arr[level][i]+rec(level+1,i));
       }
    }

    return dp[level][prev]=ans;


}
void solve(){
  cin>>n;
   arr.resize(n);
  for(int i=0;i<n;i++){
     int a,b,c;
     cin>>a>>b>>c;
     arr[i].push_back(a);
     arr[i].push_back(b);
     arr[i].push_back(c);
  }

  memset(dp,-1,sizeof(dp));
  cout<<rec(0,0)<<endl;
}
int main(){
    solve();
}