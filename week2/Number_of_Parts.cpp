#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;

int binpow(int a,int p,int mod){

if(p==0) return 1%mod;

if(p%2) return (a%mod *binpow(a,p-1,mod))%mod;

else{
int temp=binpow(a,p/2,mod);
return (temp*temp)%mod;
}

}
int ncr(int n,int r){
  // o(r) if n is to big the o(r.log(n))
  int res=1;
for(int i=0;i<r;i++){

     res = (res * ((1LL)*(n-i)) % mod) % mod;

    res = (res*binpow(i+1,mod-2,mod))%mod;
   
    
  }
  res=(res%mod+mod)%mod;
  return res;
}

void solve(){
    int n;
    cin>>n;
    int ans1=ncr(n,2)-n;
    int ans2=ncr(n,4);
    ans1=ans1%mod;
    ans2=ans2%mod;
    cout<<(ans1+ans2+1)%mod<<endl;

}
signed main(){
    ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}