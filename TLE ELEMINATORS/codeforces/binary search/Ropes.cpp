#include<bits/stdc++.h>
using namespace std;
//#define int long long 
#define endl "\n"
#define ld long double

int n,k;
int arr[100100];
bool check(ld mid){
    long long cnt=0;
    for(int i=0;i<n;i++){
        cnt+=(long long)(arr[i]/mid);
        if(cnt>=k) return true;
    }
    return false;
   
}

void solve(){
    cin>>n>>k;
    long long tot=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        tot+=arr[i];
    }

    ld lo=0.0;
    ld hi=(ld)tot;
    ld ans=0.0L;
    ld EPS=1e-7;
    while(abs(hi-lo)>=EPS){
        ld mid=(lo+hi)*(0.5L);
        if(check(mid)){
          ans=mid;
          lo=mid;
        }else{
            hi=mid;
        }
    }
   
    cout<<fixed<<ans<<setprecision(6)<<endl;
 


}
signed main(){
    solve();
}