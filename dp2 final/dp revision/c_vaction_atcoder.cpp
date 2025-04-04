#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100][4];
int dp[100100][4];
int rec(int level,int prev_index){
  // this give me maximum point , in which we have select the 
  if(level==n+1){
    return 0;
  }
  // cache check
  
  if(dp[level][prev_index]!=-1){
    return dp[level][prev_index];
  }

  // transition
  int ans=0;//
  for(int i=1;i<=3;i++){
    if(i==prev_index) continue;
    // here we making the choice and go for the next level
    ans=max(ans,arr[level][i]+rec(level+1,i));
  }
  return dp[level][prev_index]=ans;
}
vector<pair<int,pair<int,int>>>sol; // this tells which element and what index we have been selected
void generate(int level,int prev_index){
  if(level==n+1){
    return ;
  }else{
    int index=0;
    int prev=0;
    for(int i=1;i<=3;i++){
       if(i==prev_index) continue;
      int curr=arr[level][i]+rec(level+1,i);
        if(curr>prev){
           index=i;
        }
        prev=curr;
    }
    sol.push_back({level,{arr[level][index],index}});
    // here we have been push the elment and uss level ka value 
    generate(level+1,index);

  }
}
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=3;j++){
        cin>>arr[i][j];
    }
  }
  memset(dp,-1,sizeof(dp));
  cout<<rec(1,0)<<endl;
  generate(1,0);
  sort(sol.begin(),sol.end());
  int sum=0;
 for(int i=0;i<sol.size();i++){
    cout<<sol[i].first<<" "<<sol[i].second.first<<" "<<sol[i].second.second<<endl;
    sum+=sol[i].second.first;
 }
 // here sum must be equal to the rec(1,0);
 cout<<sum<<endl;
 cout<<endl;
  // here we 
}
signed main(){
    solve();
}