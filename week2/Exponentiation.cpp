#include<bits/stdc++.h>
using namespace std;
#define int long long
//int mod=1e9+7;
//int n;
//int a[1000000];
int binpow(int a,int p,int mod){

if(p==0) return 1%mod;

if(p%2) return a%mod*binpow(a,p-1,mod)%mod;

else{
int temp=binpow(a,p/2,mod);
return (temp*temp)%mod;

}

}
void solve(){
    int a,b,c,p;
    cin>>a>>b>>c>>p;
    int ans1=binpow(b,c,p-1);
    int ans2=binpow(a,ans1,p);
    cout<<(ans2%p+p)%p<<endl;

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}