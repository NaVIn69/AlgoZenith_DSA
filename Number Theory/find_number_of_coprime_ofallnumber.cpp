#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we have to find the total number of coprime of number x from 1 to 1e6
int coprime[1000100];
int is_prime[1000100];
void solve(){
    // here we sieve for finding the prime number
    for(int i=1;i<=1e6;i++){
        coprime[i]=i;
        is_prime[i]=1;
    }
    
    for(int i=2;i<=1e6;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=1e6;j+=i){
                is_prime[j]=0;
            }
        }
    }
    // here we count that how many number are coprime to the number x in between [1 , x]
    for(int i=2;i<=1e6;i++){
        if(is_prime[i]){
            for(int j=i;j<=1e6;j+=i){
                coprime[j]-=coprime[j]/i;
            }
        }
    }
  
}
signed main(){
    solve();
}