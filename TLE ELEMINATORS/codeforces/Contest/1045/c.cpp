#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    vector<int>pref(n+1,0);
    for(int i=1;i<=n;i++){
        if(i%2){
            pref[i]=pref[i-1]+(-1*arr[i]);
        }else{
            pref[i]=pref[i-1]+arr[i];
        }
    }

    int ans=0;
    int p=0;
    int x=0;
    int x_prev=0;
    for(int i=1;i<=n;i++){
        if(i>=2){
            int t=pref[i]+x;
            int need=max(0LL,p-t);
            if(need>0){
                ans += need;
                if(i%2==0){
                    x+=need;
                    x_prev+=need;
                } else {     
                    x+=need;
                }
            }
            if (i >= 2) {
                int m=pref[i-1]+x_prev;
                if(m>p) p=m;
            }
            x_prev=x;
        }
    }
    cout<<ans<<endl;

}



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

}
