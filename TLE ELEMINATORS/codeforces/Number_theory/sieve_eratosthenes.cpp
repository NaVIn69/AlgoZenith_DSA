#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int is_prime[20002000];
void sieve(int n){
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
    // here in the is_prime[i] has all the prime number between 2 t0 n 



}
void solve(){
    cin>>n;


}
signed main(){
    solve();
}