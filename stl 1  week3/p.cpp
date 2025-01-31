#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int prod=1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        prod=((arr[i]%mod)*(prod%mod))%mod;
    }
    cout<<prod<<endl;
    
    
}
signed main(){
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
}