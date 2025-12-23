#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    int arr[n],brr[m];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m;i++){
        cin>>brr[i];
    }
    sort(arr,arr+n);
    sort(brr,brr+m);
    reverse(arr,arr+n);
    reverse(brr,brr+m);
    int prefix_a[n+1]={0};
    int prefix_b[m+1]={0};
    for(int i=1;i<=n;i++){
        prefix_a[i]=prefix_a[i-1]+arr[i-1];
    }

    for(int i=1;i<=m;i++){
        
       prefix_b[i]=prefix_b[i-1]+brr[i-1];
        
    }
    while(q--){
         int x,y,z;
         cin>>x>>y>>z;
         // z select from all card , at most x from arr and y from brr
         // here we have choice , 
 
    }



}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}