#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
lli divisor(lli x){
    lli cnt=0;
    for(lli i=1;i*i<=x;i++){
        if(x%i==0){
        cnt++;
        if(i*i!=x){
            cnt++;
        }
        }
    }
    return cnt;
}
void solve(){
   lli n;
   cin>>n;
   lli ans=divisor(n);
   cout<<ans<<endl; 

}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}