#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
   int ans=0;
   map<int,int>mpp;
   for(int i=0;i<n;i++){
    int lead_z=__builtin_clzll(arr[i]);
    mpp[(63-lead_z)]++;
   }
    int  maxi=0;
    for(auto v:mpp){
        ans+=(((v.second*(v.second-1)))/2);
    }
    

   cout<<ans<<endl;
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}