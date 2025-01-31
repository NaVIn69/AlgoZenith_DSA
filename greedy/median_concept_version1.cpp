// we have to find sum(|x-xi|) for every element to be minimum
// it found to be minimum at median of array
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int median_index=(n-1)/2;
    int val=arr[median_index];
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=abs(val-arr[i]);
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