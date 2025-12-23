#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        cout<<1<<endl;
        return ;
    }
    if(n==2){
        cout<<1<<endl;
        cout<<1<<" "<<1<<endl;;
        return ;
    }
    int arr[n+2];
    arr[0]=0;
    for(int i=1;i<=n;i++){
        arr[i]=i+1;
    }
    // here we have all the prime number from 2 to n+1 all the preimse hvae 
    int is_prime[n+3];
     for(int i=2;i<=n+1;i++){
        is_prime[i]=1;
     }
    for(int i=2;i<=n+1;i++){
         if(is_prime[i]){
            for(int j=i*i;j<=n+1;j+=i){
                  is_prime[j]=2;
            }
         }
    }

    // all the prime number have same color 
    cout<<2<<endl;
    for(int i=2;i<=n+1;i++){
        cout<<is_prime[i]<<" ";
    }
    cout<<endl;



}
signed main(){
    solve();
}