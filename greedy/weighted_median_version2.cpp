// here we have given the frequency of the element 
// we have to find the sum(x-xi) minimum 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
     int n;
    cin>>n;
    int arr[n];
    int freq[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        cin>>freq[i];
    }
    // we are making the prefix of frequency array
    sort(arr,arr+n);
    for(int i=1;i<n;i++){
        freq[i]+=freq[i-1];
    }
    int median_idx=freq[n-1]/2;
    int index=lower_bound(freq,freq+n,median_idx)-freq;

    int val=arr[index];

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