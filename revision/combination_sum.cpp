#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,t;
int arr[100];
vector<int>sol;
//shared across all the 
vector<vector<int>>all_sol;
// all_sol
void rec(int level,int left){
    // total number of ways to make target from level to n-1 we have left
    if(level==n){
        if(left==0){
            all_sol.push_back(sol);
        }
        return;
    } 
    // move
    // we have choice to take that element or not
    // take the element of that level

    if(left>=arr[level]){
        sol.push_back(arr[level]);
         rec(level+1,left-arr[level]);
         sol.pop_back();
    }
    // dont take=
    rec(level+1,left);
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