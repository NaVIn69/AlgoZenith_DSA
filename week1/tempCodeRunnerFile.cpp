#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
using lld=long double;
void solve(){
    lli n;
    cin>>n;
    lli a[n];
    lli cnt=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //lli cnt=1;/
    lli ans=INT_MIN;
    lli d=a[1]-a[0];
    for(int i=0;i<n;i++){
        if(i==n-1){
            continue;
        }
        if(d+a[i]==a[i+1]){
            cnt++;
        }else{
            d=a[i+1]-a[i];
            ans=max(ans,cnt);
            cnt=2;
        }
     
    }
    ans=max(ans,cnt);
    cout<<ans<<'\n';

}
int main(){
    int t=1; 
    cin>>t;

    while(t--){
       
        solve();
    }
}