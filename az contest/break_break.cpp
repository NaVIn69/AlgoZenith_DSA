#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll a[100100];
bool check(ll mid){
    ll count_op=0;
    for(ll i=0;i<n;i++){
        if(a[i]>mid){
            count_op+=(a[i]/mid);
        }
        if(count_op>k){
            return 0;
        }
    }
   return count_op<=k;
    
}
void solve(){
cin>>n>>k;

ll e=0;

for(ll i=0;i<n;i++){ 
    cin>>a[i];
     e=max(e,a[i]);
}

ll s=0;

ll ans=0;
while(s<=e){
    ll mid=s+(e-s)/2;
    if(check(mid)){
        ans=mid;
        e=mid-1;
    }else{
        s=mid+1;
    }
}
cout<<ans<<'\n';

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}