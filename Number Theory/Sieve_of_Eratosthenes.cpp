#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int is_prime[10001000];
void sieve_of_eratosthenes(int n){
    for(int i=2;i<=n;i++){
        is_prime[i]=1;
    }
    for(int i=2;i<=n;i++){

        if(is_prime[i]){
        for(int j=i*i;j<=n;j+=i){
            is_prime[j]=0;
        }
        
     }
 }
 
}
void solve(){
    int n;
  cin>>n;
  sieve_of_eratosthenes(n);
  int cnt=0;
  for(int i=2;i<=n;i++){
    if(is_prime[i]){
     cnt++;
        cout<<i<<" ";
    }
  }

  cout<<cnt<<endl;
  // here we have to find all the prime number between 2 to n

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}