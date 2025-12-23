#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7; 
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
    int a,b,c,d,e,f,g,h;
    cin>>a>>b>>c>>d>>e>>f>>g>>h;
    int temp1=binary_expontiation(a,b,mod);
    int temp2=c%mod;
    int temp3=(d*binary_expontiation(e,mod-2,mod))%mod;
    int temp4=binary_expontiation(f,g,mod);
    int temp5=binary_expontiation(temp4,h,mod);
   cout<<(temp1-temp2-temp3+temp5+2*mod)%mod<<endl;

    



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