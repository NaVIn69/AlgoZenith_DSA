#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int MAX=3*1e5+7;
int gcd(int a,int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}
int spf[3000300];
int is_prime[3000300];
void sieve(){
    for(int i=2;i<=MAX;i++){
         is_prime[i]=1;
         spf[i]=i;
    }
    for(int i=2;i<=MAX;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=MAX;j+=i){
                is_prime[j]=0;
            }
        }
    }

    for(int i=2;i<=MAX;i++){
          if(is_prime[i]){
              for(int j=2*i;j<=MAX;j+=i){
                   spf[j]=i;
              }
          }
    }

}
vector<pair<int,int>>prime_fact(int x){
    map<int,int>mpp;
    
     while(x>1){
        mpp[spf[x]]++;
        x/=spf[x];
     }
     vector<pair<int,int>>v(mpp.begin(),mpp.end());
     return v;
}
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>prefix_gcd(n),suffix_gcd(n);
    prefix_gcd[0]=arr[0];
    for(int i=1;i<n;i++){
       prefix_gcd[i]=gcd(prefix_gcd[i-1],arr[i]);
    }
    suffix_gcd[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffix_gcd[i]=gcd(suffix_gcd[i+1],arr[i]);
    }
    // here if the i id the stronge index then gcd([1..i-1],[i+1...n])
    int g=suffix_gcd[0];
    int ans=0;
    int new_gcd=0;
    for(int i=0;i<n;i++){
        if(i==0){
             new_gcd=suffix_gcd[i+1];
            if(new_gcd!=1){
                ans++;
            }
        }else if(i==n-1){
             new_gcd=prefix_gcd[i-1];
            if(new_gcd!=1){
              ans++;
            }
        }else{
            int prefix_g=prefix_gcd[i-1];
            int suffix_g=suffix_gcd[i+1];
            new_gcd=gcd(prefix_g,suffix_g);
            if(new_gcd!=1){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
   


}
signed main(){
    int t=1;
    cin>>t;
    sieve();
    while(t--){
        solve();
    }
}