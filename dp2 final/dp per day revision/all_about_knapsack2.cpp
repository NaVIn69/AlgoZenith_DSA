#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k,w;
int weight[1001];
int val[1001];
int dp[105][1005][105];
int rec(int level,int wleft,int item_left){
    // this function return the maximum val from (level...n) by selecting the item_left item and wleft 
    if(level==n){
        return 0;
    }
    // cache check
   if(dp[level][wleft][item_left]!=-1){
    return dp[level][wleft][item_left];
   }
    // compute transition
   // dont take
   int ans=rec(level+1,wleft,item_left);
   // take
   if(weight[level]>=wleft){
    ans=max(ans,val[level]+rec(level+1,wleft-weight[level],item_left-1));
   }
  return dp[level][wleft][item_left]=ans;

}
vector<int>sol;
void generate(int i,int x,int item_left){
    if(i==n){
        return ;
    }else{
        int donttake=rec(i+1,x,item_left);
        int take=rec(i+1,x-weight[i],item_left-1);
        if(take>donttake){
            sol.push_back(i);
            generate(i+1,x-weight[i],item_left-1);
        }else{
            generate(i+1,x,item_left);
        }

    }
}
void solve(){
    cin>>n>>w>>k;
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
  memset(dp,-1,sizeof(dp));
  cout<<rec(0,w,k)<<endl;
  for(int i=0;i<sol.size();i++){
    cout<<sol[i]<<" ";
  }
  cout<<endl;  

} 
signed main(){
    solve();
}