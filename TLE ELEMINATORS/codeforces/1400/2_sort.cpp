#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(k==0){
        cout<<n<<endl;
        return;
    }
    int cnt=0,ans=0;
    for(int i=0;i+1<n;i++){
        if(a[i]<2*a[i+1])cnt++;
        else cnt=0;
        if(cnt>=k)++ans;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
