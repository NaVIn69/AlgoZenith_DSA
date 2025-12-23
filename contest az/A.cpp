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
    vector<int>freq(n);
    int sum=0;
    freq[sum]++;
    int cnt=0;
    for(int i=0;i<n;i++){
        sum=(sum+arr[i]%n+n)%n;
       cnt+=freq[sum];
       freq[sum]++;
        
    }
    cout<<cnt<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
}