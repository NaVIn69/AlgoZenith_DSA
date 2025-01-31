#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
 int n;
 cin>>n;
 int arr[n],brr[n];
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 for(int i=0;i<n;i++){
    cin>>brr[i];
 }
 sort(arr,arr+n);
 sort(brr,brr+n);
 //reverse(brr,brr+n);
 int sum=0;
 for(int i=0;i<n;i++){
    sum+=abs(arr[i]-brr[i]);
 }
 cout<<sum<<endl;
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