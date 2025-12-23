#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
  int n,k,m;
  cin>>n>>k>>m;
  int brr[n];
  pair<int,int>arr[n];
  map<int,vector<int>>mpp;
  for(int i=0;i<n;i++){
    cin>>brr[i];
    arr[i].first=brr[i]%m;
    arr[i].second=i;
    mpp[arr[i].first].push_back(i);
  }
  for(auto x:mpp){
      int sz=x.second.size();
      if(sz>=k){
        int cnt=0;
        cout<<"Yes"<<endl;
        for(int y:x.second){
            cnt++;
           
            cout<<brr[y]<<" ";
            if(cnt==k){
                break;
            }
        }
        cout<<endl;
        return ;
      }
  }
  cout<<"No"<<endl;
  

}
signed main(){
    solve();
}