#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(auto&v:a) cin>>v;
    int cnt=0;
    sort(a,a+n);
    map<int,int>mpp;
    for(int i=0;i<n;i++){
          int find=a[i]-k;
          if(find<0){
            mpp[a[i]]++;
            continue;
          }
          if(mpp.find(find)!=mpp.end()){
            cnt+=mpp[find];
          }
          mpp[a[i]]++;
    }
      cout<<cnt<<endl;
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}