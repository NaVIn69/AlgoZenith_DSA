#include<bits/stdc++.h>
using namespace std;
#define int long long
bool is_prime(int x){
    for(int i=2;i*i<=x;i++){
      if(x%i==0){
      return false;
      }
    }
    return true;

}
void solve(){
    int x;
    cin>>x;
    if(x==1){
cout<<"N0"<<'\n';
        return;
    }
bool ans=is_prime(x);   
    if(ans){
cout<<"YES"<<endl;
    }else{
cout<<"NO"<<endl;
    }


}
signed main(){
int t=1;
    cin>>t;
    while(t--){
        
        solve();
    }
}