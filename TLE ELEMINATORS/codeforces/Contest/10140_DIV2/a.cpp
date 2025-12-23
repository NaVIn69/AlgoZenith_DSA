#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    int cnt0=0,cnt1=0;
    for(int i=0;i<n;i++){
         cin>>arr[i];
         sum+=arr[i];
         if(arr[i]==0)cnt0++;
         else if(arr[i]==1)cnt1++;
    }
    sort(arr,arr+n);
    int ans=sum+cnt0;
    cout<<ans<<endl;


}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
