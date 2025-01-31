#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
lli mod=1e9+7;
void solve(){
    lli n;
    cin>>n;
    // number of diagonal of n polygon nc2-n=n(n-3)/2;
  lli ans=((1LL*n*(n-3))/2)%mod;
   cout<<(ans%mod+mod)%mod<<'\n';

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}