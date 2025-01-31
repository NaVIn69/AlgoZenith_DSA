#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];
void solve(){
    cin>>n;
    int b[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        b[i]=arr[i];
    }
    sort(arr,arr+n);
    sort(b,b+n);
    reverse(b,b+n);
    // to find the min_value(a1b1+a2*b2+a3*b3+.....)
   int ans=0;
   for(int i=0;i<n;i++){
    ans+=(arr[i]*b[i]);
   }
   cout<<ans<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
}