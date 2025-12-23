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
ll a,b,c,d,e,f,g;
cin>>a>>b>>c>>d>>e>>f>>g;
ll temp1=(binary_exp(a,b,mod)-c)%mod;
ll temp2=(temp1-d*(binary_exp(d,mod-2,mod)%mod))%mod;
ll fg=binary_exp(f,g,mod);
ll h=binary_exp(fg,h,mod);

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}