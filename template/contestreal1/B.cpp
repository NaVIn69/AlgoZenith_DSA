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
  string s;
  cin>>s;
  int index_eq=s.find('=');
  int index_x=s.find('X');
  int ans=0;
  if(index_eq>index_x){
    char ch=s[index_eq+1];
    ans=int(ch)-48;
    for(int i=index_eq+1;s[i]!='\0';i++){
       if(s[i]!='-'|| s[i]!='+'){
        
       }
    }
  }
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