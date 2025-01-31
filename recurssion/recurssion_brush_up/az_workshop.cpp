#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,x,k;
int tim[1001];
int skill[1001];
int taken[1001];
bool check(int level){
   int time_taken=0;
   int slot_taken=0;
   for(int i=0;i<level;i++){
      if(taken[i]){
        time_taken+=tim[i];
        slot_taken++;
      }
   }
   time_taken+=tim[level];
   slot_taken++;
   if(slot_taken<=k&&time_taken<=x){
    return 1;
   }else {
    return 0;
   }
}
int rec(int level){
    // this function gives me from that function what is the maximum value i can obtain
    // base case
    if(level==n){
        return 0;
    }
    // choice 
    // take 
    int ans=rec(level+1);
    if(check(level)){
        taken[level]=1;
     ans=max(ans, skill[level]+rec(level+1));
        taken[level]=0;
    }

    // dont take
  return ans;

}
void solve(){
  cin>>n>>x>>k;
  for(int i=0;i<n;i++){
    cin>>tim[i];
  }
  for(int i=0;i<n;i++){
    cin>>skill[i];
  }
  cout<<rec(0)<<endl;


}
signed main(){
    solve();
}