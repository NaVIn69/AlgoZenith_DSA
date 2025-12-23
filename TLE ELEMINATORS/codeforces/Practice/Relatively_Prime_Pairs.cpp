#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int l,r;
void solve(){
 cin>>l>>r;
 //gcd(a,b)-> odd event 

 cout<<"YES"<<endl;
  while(l<r){
   cout<<l<<" "<<l+1<<endl;
   l+=2;
     
  }

}
signed main(){
    solve();
}