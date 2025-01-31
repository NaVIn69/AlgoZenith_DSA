#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
   map<int,int>mpp;
   for(int i=0;i<n;i++){
    cin>>arr[i];
  
   }
    int cnt=0;
    sort(arr,arr+n);
     for(int i=0;i<n;i++){
        int maxi=k+arr[i];
        int mini=arr[i]-k;
        int occ_mini=(upper_bound(arr+i,arr+n,mini)-arr)-(lower_bound(arr+i,arr+n,mini)-arr);
        int occ_maxi=(upper_bound(arr+i,arr+n,maxi)-arr)-(lower_bound(arr+i,arr+n,maxi)-arr);
        cnt+=(occ_maxi+occ_mini);
    }
    cout<<cnt<<endl;
    
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