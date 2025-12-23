#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// number is not prime then that number is composite number 
bool is_prime[10001000];
vector<int>all_prime;

void prime_check(int n){
    for(int i=2;i<=n;i++){
        is_prime[i]=1;
    }
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
          all_prime.push_back(i);
            for(int j=i;j<=n;j+=i){
                is_prime[j]=0;
            }
        }
    }
}

int n;
void solve(){
 cin>>n; // that many we have to  
 // for n size prime number 
 int x=55555;
 prime_check(x);
 vector<int>prefix(n+1,0);
 for(int i=0;i<n;i++){
    
 }

   
}
signed main(){
    solve();
}