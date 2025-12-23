#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    int arr[n],brr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i]>>brr[i];
    }
    pair<int,int>crr[n];
    for(int i=0;i<n;i++){
        crr[i].first=arr[i]-brr[i];
        crr[i].second=i;
    }
    // here we have to minimize sum of crr[i]*i for each index
    sort(crr,crr+n);
    reverse(crr,crr+n);
    // for(int i=0;i<n;i++){
    //     cout<<crr[i].second<<" ";
    // }
    // cout<<endl;
    int ans=0;
    for(int i=0;i<n;i++){
        int idx=crr[i].second;
       int a=arr[idx];
       int b=brr[idx];
       int val=a*i+b*(n-i-1);
       ans+=val;
    }
    cout<<ans<<endl;



}
signed main(){
    solve();
}