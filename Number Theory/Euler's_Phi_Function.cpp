// here we have to count the total coprime number with x gcd(x,a)=1
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we have to find the total number of coprime of number x from 1 to 1e6
int coprime[1000100];
int is_prime[1000100];
void solve(){
    // here we sieve for finding the prime number
  int n;
  cin>>n;
  vector<pair<int,int>>prime;
  int ans=n ;// let assume we have n coprime number now we substract all the multiple of prime number 

  // here we are finding all the prime factor of number n , then we substract all the multiple of that prime number which is less than  n
  for(int i=2;i*i<=n;i++){

      if(n%i==0){
        int cnt=0;
        bool check=false;
         while(n%i==0){
           cnt++;
           n/=i;
           check=true;
         }  
         if(check){
          ans/=i;
          ans*=(i-1);
         }
         
      }
  }

  if(n>1){
     ans/=n;
     ans*=(n-1);
  }
  // tc = sqrt(n);
  cout<<ans<<endl;
  
  
}
signed main(){
    solve();
}