#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll binary_exp(ll a,ll b,ll mod){
if(b==0) return 1%mod;
if(b%2==1) return a*binary_exp(a,b-1,mod)%mod;
else {
   ll temp=binary_exp(a,b/2,mod);
    return (temp*temp)%mod;
}
}
void solve(){
    ll a,b,c,p;
    cin>>a>>b>>c>>p;
    ll ab=binary_exp(a,b,p);
    ll ans=binary_exp(ab,c,p);
    cout<<((ans%p)+p)%p<<endl;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}