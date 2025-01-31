// here we generating all the possible solution 
// smallest lexicographical all permutation
// beacause we are traversing in the map
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];
map<int,int>mpp;
vector<vector<int>>all_sol;
vector<int>curr_prem;
void rec(int level){
    if(level==n){

        all_sol.push_back(curr_prem);
        return;
    }

    // choice
    // here we can take every element at 
    // this is all my choice
    for(auto v:mpp){
        if(v.second!=0){
            // cout<<"level"<<" "<<level<<" "<<endl;
         
            mpp[v.first]--;
            curr_prem.push_back(v.first);
            // // cout<<"before"<<endl;
            //   for(auto x:curr_prem){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
            rec(level+1);
            curr_prem.pop_back();
            // cout<<"after"<<endl;;
            //  for(auto x:curr_prem){
            //     cout<<x<<" ";
            // }
          //  cout<<endl;

            mpp[v.first]++;
        }
    }
    




}

 void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    mpp[arr[i]]++;
  }
  rec(0);
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