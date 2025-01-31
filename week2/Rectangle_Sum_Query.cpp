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

// lcm of two number a,b

int lcm(int a,int b){
  return (a*b)/gcd(a,b);
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
// struct monotone deque to maintain the minimum of all element
struct monotone_deque{
  deque<int>dq;
  void insert(int x){
     while(!dq.empty()&&dq.back()>x){
        dq.pop_back();
     }
     dq.push_back(x);
  }
// erase
void erase(int x){
   if(dq.front()==x){
    dq.pop_front();
   }
}

// getmin value from deque
int getmin(){
  return dq.front();
}

};


void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    // here we are making prefix array by 1 based index array
    int p[n+1][m+1];
    // here we are making the 2d prefix array
  
    for(int i=0;i<m+1;i++){
        p[0][i]=0;

      
    }
   
    for(int j=0;j<n+1;j++ ){
        p[j][0]=0;
       
       
    }
    for(int i=1;i<n+1;i++){

        for(int j=1;j<m+1;j++){
          // here we do one based index that why we do i-1 and j-1 int array a[i-1][j-1]
           p[i][j]=(((a[i-1][j-1]%mod+p[i-1][j]%mod)%mod+p[i][j-1]%mod)%mod-p[i-1][j-1]%mod)%mod;
          
        }
    }
   while(q--){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    
    int ans=(((p[x2][y2]%mod-p[x2][y1-1]%mod)%mod-p[x1-1][y2]%mod)+p[x1-1][y1-1]%mod)%mod;
    cout<<(ans%mod+mod)%mod<<endl;
    
   }
    
  



}
signed main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
    int t=1;
    // cin>>t;
     while(t--){
        solve();
     }
}