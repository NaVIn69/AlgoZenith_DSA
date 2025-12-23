#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.rbegin(),a.rend());
    int mini=min(n,m);
    int ans=0;
    for(int i=0;i<mini;i++){
       int t=m-i;
       ans+=(a[i]*t);
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