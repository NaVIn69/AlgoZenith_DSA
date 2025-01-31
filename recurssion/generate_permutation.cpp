#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n;
vector<vector<int>>all_sol;
vector<int>curr_prem;
map<int,int>mpp;
void rec(int level){
    // here level is the index 
    // base case
    if(level==n){
        all_sol.push_back(curr_prem);
        return;
    }
    // recursive case
    for(auto v:mpp){
        if(v.second!=0){
            //palce the element
            mpp[v.first]--;
            curr_prem.push_back(v.first);
            //move to the next level
            rec(level+1);
            //unplace
            curr_prem.pop_back();
            mpp[v.first]++;

        }
    }
}
void solve(){
cin>>n;
int a[n];
for(int i=0;i<n;i++){
  cin>>a[i];
  mpp[a[i]]++;
}
rec(0);
for(int i=0;i<all_sol.size();i++){
    vector<int>v1=all_sol[i];
    for(int j=0;j<v1.size();j++){
        cout<<v1[j]<<" ";
    }
    cout<<endl;
}
 
  
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}