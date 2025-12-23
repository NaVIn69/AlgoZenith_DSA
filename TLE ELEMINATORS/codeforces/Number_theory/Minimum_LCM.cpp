#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int gcd(int a,int b){
    if(a==0){
        return b;
   }
   return gcd(b%a,a);
}
int lcm(int a,int b){
    int g=gcd(a,b);
    return (a*b)/g;
}
void solve(){
  int n;
  cin>>n;
  vector<int>divisor;
  for(int i=1;i*i<=n;i++){
      if(n%i==0){
         divisor.push_back(i);
         if(i*i!=n){
            divisor.push_back(n/i);
         }
      }
  }
  sort(divisor.begin(),divisor.end());
//   for(auto x:divisor){
//     cout<<x<<" ";
//   }
//   cout<<endl;
  int mini=1e9+8;

  int div=0;
  int r=0;
  for(int i=0;i<divisor.size();i++){
      int rem=n-divisor[i];
      if(rem<=0)break;
     
            int l=lcm(divisor[i],rem);
            mini=min(l,mini);
            if(mini==l){
                div=divisor[i];
                r=rem;
            }
        }
        cout<<div<<" "<<r<<endl;
      
            
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}