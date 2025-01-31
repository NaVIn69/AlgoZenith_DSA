#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int n;
int a[1000000];

//gcd of a and b ;; gcd(gcd(a,b),c)-> a b,c ka gcd

int gcd(int a,int b){
  
 if(a==0){
   return b;

 }
 return gcd(b%a,a);
    
}


// a^p%mod 

int binpow(int a,int p,int mod){

if(p==0) return 1%mod;

if(p%2) return a*binpow(a,p-1,mod)%mod;

else{
int temp=binpow(a,p/2,mod);
return (temp*temp)%mod;
}

}
// ncr 
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
// factorial function


  
void solve(){
    int n;
    cin>>n;
    int ans=ncr(n,2);
    ans++;
    cout<<(ans%mod+mod)%mod<<endl;

}
signed main(){
    int t=1;
     cin>>t;
     while(t--){
        solve();
     }
}