#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
int ans=0;
for(int i=0;i<n;i++){
    ans=ans^a[i];
}
cout<<ans<<'\n';

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();        
        
    }
}