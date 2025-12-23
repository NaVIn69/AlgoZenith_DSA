#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];
bool check(int mid){
    int cnt=1;
    int prev=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>=(prev+mid)){
            cnt++;
            if(cnt>=k) return true;
            prev=arr[i];
        }
       
    }
    return false;
}
void solve(){
    cin>>n>>k;
    int mini_diff=0;
    int max_diff=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    sort(arr,arr+n);
    for(int i=1;i<n;i++){
        mini_diff=min(mini_diff,arr[i]-arr[i-1]);
    }
    max_diff=arr[n-1]-arr[0];
    int ans=mini_diff;
   while(mini_diff<=max_diff){
    int mid=(mini_diff+max_diff)/2;
    if(check(mid)){
      ans=mid;
      mini_diff=mid+1;

    }else{
        max_diff=mid-1;
    }
   }
   cout<<ans<<endl;

}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}