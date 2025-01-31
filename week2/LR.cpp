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
// x^y
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
int sum_l_r(vector<int>prefix,int l,int r){
  if(l==0) return prefix[r];
  else return prefix[r]-prefix[l-1];
}



const int N=1000001;
void solve(){
int n,q,k;
cin>>n>>q>>k;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
    
}
// building the prefix sum
vector<int>prefix(n);
prefix[0]=(arr[0]*k)%mod;
for(int i=1;i<n;i++){
    prefix[i]=(prefix[i-1]+((arr[i]%mod)*(binpow(k,i+1,mod)%mod))%mod)%mod;  // here it take maximum time upto nlog(n);
    if(prefix[i]>=mod){
        prefix[i]-=mod;
    }
    if(prefix[i]<0){
        prefix[i]+=mod;
    }
    
}

// here we are making the kinverse array
vector<int>kinverse(N);
kinverse[0]=(binpow(k,mod-2,mod))%mod;
int x=kinverse[0];
for(int i=1;i<10;i++){
    kinverse[i]=(kinverse[i-1]*x)%mod;
    if(kinverse[i]>=mod){
        kinverse[i]-=mod;
    }
    if(kinverse[i]<0){
        kinverse[i]+=mod;
    }
  
   
}
// here we are solving the query
while(q--){
    int l,r;
    cin>>l>>r;
    l--;
    r--;
    int prefix_sum=sum_l_r(prefix,l,r)%mod;
    if(prefix_sum<0){
        prefix_sum+=mod;
    }
    if(prefix_sum>=mod){
        prefix_sum-=mod;
    }
    int kinv=kinverse[l]%mod;
    if(kinv<0){
        kinv+=mod;
    }
    if(kinv>=mod){
        kinv-=mod;
    }
    int ans=(prefix_sum*kinv)%mod;
    cout<<(ans%mod+mod)%mod<<endl;
}

}
signed main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
    int t=1;
 
     while(t--){
        solve();
     }
}