#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,w;
int weight[10001];
int value[10001];
int taken[10001];
int check(int level){
  int sum_wt=0;
  for(int i=0;i<level;i++){
    if(taken[i]){
      sum_wt+=weight[i];
    }
  }
  sum_wt+=weight[level];
  if(sum_wt<=w) return 1;
  else return 0;
}
int rec(int level){
   if(level==n){
    return 0;
   }
   // choice dont take it
   int ans=rec(level+1);

   // choice take it
   if(check(level)){
     taken[level]=1;
     ans=max(ans,value[level]+rec(level+1));
   }
   taken[level]=0;
   return ans;
}
void solve(){
  cin>>n>>w;
  for(int i=0;i<n;i++){
    cin>>weight[i]>>value[i];
  }
  cout<<rec(0)<<endl;

}
signed main(){
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}