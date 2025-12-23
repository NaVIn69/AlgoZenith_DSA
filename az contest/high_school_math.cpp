#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+9; 
int binary_expontiation(int a,int b,int mod){

  int ans=1;

  while(b>0){
  
  if(b%2){
    ans=((a%mod)*(ans%mod)) %mod;
  }
  a= ((a%mod)*(a%mod))%mod;
  b/=2;

  }
  return ans;
}
void solve(){
    int a,b,n;
    cin>>a>>b>>n;
    if(n==1){
        cout<<(a%mod+b%mod)%mod<<endl;
        return;
    }
    if(a==1){
        int ans=n%mod*b%mod;
        cout<<(1+ans)%mod<<endl;
        return ;
    }
    int ans=binary_expontiation(a,n,mod);
   
   int ans3=b*(ans-1)%mod;
   int ans4=ans3*binary_expontiation(a-1,mod-2,mod)%mod;
   cout<<(ans%mod+ans4%mod+mod)%mod<<endl;




    



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