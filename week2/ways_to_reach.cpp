#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;


using pi=pair<int,int>;

//gcd of a and b ;; gcd(gcd(a,b),c)-> a b,c ka gcd

int gcd(int a,int b){
  
 if(a==0){
   return b;

 }
 return gcd(b%a,a);
    
}
// number is either prime or composite number
bool check_isprime(int n){

  for(int i=2;i*i<n;i++){

    if(n%i==0) return 0;

  }
  return 1;
}
// divisor of number n=d1*d2 d1 belongs to the (1,root(n)) and d2 belongs to the (root(n)+1,n) here first when we find the first diviosr then we also find the second the second divisor

vector<int> divisor(int n){
  vector<int>ans;
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
      ans.push_back(i);
      if(i*i!=n){
        ans.push_back(n/i);
      }
    }

  }
  return ans;
}


// prime factorisition of all number
vector<pi>prime_factorisation(int n){
  vector<pi>ans;
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      int cnt=0;
      while(n%i==0){
        cnt++;
        n/=i;
      }
      ans.push_back({i,cnt});
    }
  }
  if(n>1){
    ans.push_back({n,1});
  }
  return ans;


}
// a^p%mod 
// iterative binay exponatiation
int binary_expontiation(int a,int b,int mod){

  int ans=1;

  while(b){
  
  if(b%2 == 1){
    ans=((a%mod)*(ans%mod)) %mod;
  }
  a= ((a%mod)*(a%mod))%mod;
  b/=2;

  }
  return ans;
}

// recursive binary exponatiaton
int binpow(int a,int p,int mod){
    

if(p==0) return 1%mod;

if(p%2) return (a%mod *binpow(a,p-1,mod))%mod;

else{
int temp=binpow(a,p/2,mod);
return (temp*temp)%mod;
}

}


// inverse binary_expontion
int inverse_binpow(int a,int b,int mod){
// a^-1%mod==

  return binpow(a,mod-2,mod);

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
int fact[1000001];
void factorial(){
    fact[0]=1;
    for(int i=1;i<1000001;i++){
        fact[i]=((i%mod)*(fact[i-1]%mod))%mod;
    }
}


  
void solve(){
    int n,m;
    cin>>n>>m;
    int k=(n%mod+m%mod)%mod;
    int numo=fact[k];
    int demo=((fact[n]%mod)*(fact[m]%mod))%mod;
    int ans=(numo*binpow(demo,mod-2,mod))%mod;
   
    cout<<(ans%mod+mod)%mod<<endl;

    
    


}
signed main(){
    int t=1;
  factorial();
     cin>>t;
     while(t--){
        solve();
     }
    
}