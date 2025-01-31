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
int sum_l_r(vector<int>prefix,int l,int r){
  if(l==0) return prefix[r];
  else return prefix[r]-prefix[l-1];
}
int power(int x,int y){
  int res=1;
  while(y){
    if(y%2){
      res =((res%mod)*(x%mod))%mod;
    }
    x=((x%mod)*(x%mod))%mod;
    y=y/2;
  }
  return res%mod;
}


  const int N=1000001;
void solve(){
int n,q,k;
cin>>n>>q>>k;
vector<int>arr;
// here we generate the power of k;
vector<int>powerK;
vector<int>prefix;
powerK[0]=1;
for(int i=1;i<=N;i++){
  powerK[i]=((k%mod)*(powerK[i-1]%mod))%mod;
}

for(int i=1;i<=n;i++){
    cin>>arr[i];
   
   arr[i]=(arr[i]*powerK[i])%mod;
   if(arr[i]<0){
    arr[i]+=mod;
   }
}
// make prefix array a[i]*k^i

 prefix[0]=0;
for(int i=1;i<=n;i++){
  prefix[i]=prefix[i-1]+arr[i];
  if(prefix[i]>=mod){
    prefix[i]-=mod;

  }
  cout<<prefix[i]<<" ";

}
/*cout<<endl;*/
// now make the k^-l array
// first calculate k^-1;
/*vector<int>kinverse(1e6+1,0);
 kinverse[0]= binpow(k,mod-2,mod)%mod;
for(int i=1;i<10;i++){
  kinverse[i]=((kinverse[i-1]%mod)*(kinverse[0]%mod))%mod;
  kinverse[i]=(kinverse[i]%mod+mod)%mod;
}*/


while(q--){
  int l,r;
  cin>>l>>r;
  int prefix_sum=prefix[r]-prefix[l-1];
  if(prefix_sum<0){
    prefix_sum+=mod;
  }
  int ans=(prefix_sum*binpow(powerK[l],mod-2,mod))%mod;
  
  cout<<ans<<endl;

}



}
signed main(){
    int t=1;
     while(t--){
        solve();
     }
}