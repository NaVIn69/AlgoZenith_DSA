#include<bits/stdc++.h>
using namespace std;
#define int long long 
int mod=1e9+7;

int binpow(int a,int p,int mod){
if(p==0) return 1%mod;

if(p%2) return a*binpow(a,p-1,mod)%mod;

else{
int temp=binpow(a,p/2,mod);
return (temp*temp)%mod;
}
}
void solve(){
    int n;
    cin>>n;
    
  int res=1;
  for(int i=0;i<4;i++){

     res = (res * ((1LL)*(n-i)) % mod) % mod;

    res = (res*binpow(i+1,mod-2,mod))%mod;
   
    
  }
  cout<<(res%mod+mod)%mod<<endl;
  

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int mod = 1e9 + 7;

int binpow(int a, int p, int mod) {
    if (p == 0) return 1 % mod;
    if (p % 2) return a * binpow(a, p - 1, mod) % mod;
    else {
        int temp = binpow(a, p / 2, mod);
        return (temp * temp) % mod;
    }
}

void solve() {
    int n;
    cin >> n;
  
    int res = 1;
    for (int i = 0; i < 4; i++) {
        res *= ((1LL) * (n - i)) % mod;
        res = (res * binpow(i + 1, mod - 2, mod)) % mod;
        res = (res + mod) % mod;
    }
    cout << res << endl;
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
*/