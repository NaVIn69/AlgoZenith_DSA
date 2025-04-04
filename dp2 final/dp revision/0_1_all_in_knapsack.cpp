#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we have 0-1 knapsack problem  and 0-inf knapsack problem
// maximum k items
// if u take ith then u cant take i+1th items
// generate the solution
// find the maximum value

int n,w,k;
int wt[101];
int val[101];
int dp[100][1001][100];

int rec(int level,int wleft,int rem_items){
    if(level>=n){
        // base case
        return 0;
    }
    // cache check

    // transition -> choice
    int ans=0;
    // take
    if(rem_items!=0&&wleft>=wt[level]){
        // if we take level then we cant take level+1 that why i jump to level+2 
        ans=max(ans,val[level]+rec(level+2,wleft-wt[level],rem_items-1));
    }
    // dont take
    // we are not taking the level+1
    ans=max(ans,rec(level+1,wleft,rem_items));

    return ans;
}
vector<int>solution;
void generate(int level,int wleft,int rem_item){
    // base case
    if(level>=n){
        return ;
    }else{
       int take=0;
       if(rem_item!=0&&wleft>=wt[level]){
        take=max(take,val[level]+rec(level+2,wleft-wt[level],rem_item-1));
       }
       // dont t
       int donttake=rec(level+1,wleft,rem_item);
       if(take>=donttake){
           solution.push_back(val[level]);
           generate(level+2,wleft-wt[level],rem_item-1);
       }else{
          // here we dont take that element
          generate(level+1,wleft,rem_item);
       }
    }
}
void solve(){
    cin>>n>>w>>k;
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }

    memset(dp,-1,sizeof(dp));
    cout<<rec(0,w,k)<<endl;
    generate(0,w,k);
    // here we redoing same stuff and generating the solution
    for(int i=0;i<solution.size();i++){
        cout<<solution[i]<<" ";
    }
    cout<<endl;

    

}
signed main(){
   solve();
}