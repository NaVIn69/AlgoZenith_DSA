#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
/// 0-1 
int n,t;
int arr[101];
vector<int>sol;
vector<vector<int>>all_sol;
void rec(int level,int target){
     

    if(level==n){
        if(target==0){
            all_sol.push_back(sol);
        }
        return;
    }
    // choice
    // take
    if(arr[level]<=target){
        // means we taking that element in our subset
        sol.push_back(arr[level]);


        // this recursive code is for 0-1 knapsack
    //    rec(level+1,target-arr[level]);


       // here this recursive call is for thr 0-inf knapsack
       rec(level,target-arr[level]);
       sol.pop_back();
    }
    // dont take
    rec(level+1,target);

}
void solve(){
   cin>>n>>t;
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   rec(0,t);
   for(int i=0;i<all_sol.size();i++){
    for(int j=0;j<all_sol[i].size();j++){
        cout<<all_sol[i][j]<<" ";
    }
    cout<<endl;
   }

}
signed main(){
    solve();
}