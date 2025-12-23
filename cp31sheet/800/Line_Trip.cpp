#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int max_diff=a[0];
    for(int i=1;i<n;i++){
        int k=a[i]-a[i-1];
        max_diff=max(max_diff,k);
    }
    int index=lower_bound(a,a+n,x)-a;
    
    if(index==n){
        int k=x-a[n-1];
        max_diff=max(max_diff,2*k);
        cout<<max_diff<<endl;
    }else{
        int k=a[index]-a[index-1];
        int p=2*(x-a[index-1]);
        int l=min(k,p);
        max_diff=max(l,max_diff);
        cout<<max_diff<<endl;
    }


}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}