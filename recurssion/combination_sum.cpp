#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,t;
int arr[100100];
vector<vector<int>>ans;
// this vector is shared across the recurssion
// here we can choose the single element multiple time
vector<int>ele;
void rec(int level,int target){
    if(level==n){
        if(target==0){
            ans.push_back(ele);
        }
        return;
    }
    if(target==0){
        ans.push_back(ele);
        return;
    }
    // choice
    //take
    if(target>=arr[level]){
        //place
        ele.push_back(arr[level]);
        //move
       rec(level,target-arr[level]); 
       //unplace
       ele.pop_back();
    }
    //dont take
        rec(level+1,target);
    


}
void solve(){
  cin>>n>>t;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  rec(0,t);
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }

}
signed main(){
    solve();
}