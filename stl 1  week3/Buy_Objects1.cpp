#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m;
    cin>>n>>m;
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
    int index=upper_bound(p,p+n,m)-p;
    cout<<index<<endl;
}
signed main(){
    ios_base::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}