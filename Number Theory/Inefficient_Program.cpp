#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
  int l,r,m;
  cin>>l>>r>>m;
  // number of repetation of [0..m-1] number in between l to r
  int rep=0;
  if(r>=(2*m)){
    rep=(r-l+1)/m;
  }
  int sm=((((m-1)%mod)*(m%mod))/2)%mod;
  int first_tot=((rep%mod)*(sm%mod))%mod;
  // left side remaning ele ka sum
  int left_sum=(sm-((((l-1)%mod)*(l%mod))/2)+mod)%mod;
  
  // right side remaning ele ka sum
//   int right_ele=(r-m); // number of element which is less than m from 1 .... right ele
//   int right_sum=0;
//   if(right_ele>0){
//    right_sum=((((right_ele+1)%mod)*(right_ele%mod))/2)%mod;
//   }
int rem=r%m;
  int right_sum=0;
  if(rem>0){
   right_sum=((((rem+1)%mod)*(rem%mod))/2)%mod;
  }


cout<<first_tot<<" "<<left_sum<<" "<<right_sum<<endl;
  cout<<(first_tot%mod+left_sum%mod+right_sum%mod+mod)%mod<<endl;



}
signed main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}