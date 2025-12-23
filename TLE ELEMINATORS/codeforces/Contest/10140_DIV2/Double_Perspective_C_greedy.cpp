#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>>v(n,{{0,0},0});
    for(int i=0;i<n;i++){
        cin>>v[i].first.first>>v[i].first.second;
        v[i].first.second=-v[i].first.second; // after sorting we get bigger b with same starting point
        v[i].second=i+1;// one based real index store
    }
    // for avoiding the cycle we have to chose set of unique starting point with larger b;
    sort(v.begin(),v.end());
    int check=-1e9;
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(v[i].first.first>check){
            check=v[i].first.first;
            ans.push_back(v[i].second);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}
signed main(){
  int t=1;
  cin>>t;
  while(t--){
    solve();
  }
}