#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
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
void solve(){
  int n;
  cin>>n;
  int total=binary_expontiation(26,n,mod);
  int only_cons=binary_expontiation(21,n,mod);
  int only_vowels=binary_expontiation(5,n,mod);
  int ans=(total-(only_cons%mod+only_vowels%mod)%mod)%mod;
  cout<<(ans%mod+mod)%mod<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}