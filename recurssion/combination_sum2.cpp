#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,t;
int arr[100100];
set<vector<int>>ans;
vector<int>ele;
void rec(int level,int target){
    if(level==n){
        if(target==0){
            vector<int>temp(ele.begin(),ele.end());

            sort(temp.begin(),temp.end());
            ans.insert(temp);
        }
        return;
    }
    if(target==0){
        vector<int>temp(ele.begin(),ele.end());

            sort(temp.begin(),temp.end());
        ans.insert(temp);
        return;
    }
    if(target>=arr[level]){
        ele.push_back(arr[level]);
       rec(level+1,target-arr[level]);
       ele.pop_back();
    }
    rec(level+1,target);
}
void solve(){
  cin>>n>>t;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  rec(0,t);
  vector<vector<int>>ans2(ans.begin(),ans.end());
  for(int i=0;i<ans2.size();i++){
    for(int j=0;j<ans2[i].size();j++){
        cout<<ans2[i][j]<<" ";
    }
    cout<<endl;
  }
}
signed main(){
    solve();
}