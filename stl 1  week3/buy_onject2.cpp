#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,q;
    cin>>n>>q;
    int a[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int p[n];
    for(int i=0;i<n;i++){
         p[i]=a[i];
        if(i) p[i]+=p[i-1];
    }
    while(q--){
        int m;
        cin>>m;
        cout<<upper_bound(p,p+n,m)-p<<endl;
    }
    
}
signed main(){
    ios_base::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);
    int t=1;
   
    while(t--){
        solve();
    }
}