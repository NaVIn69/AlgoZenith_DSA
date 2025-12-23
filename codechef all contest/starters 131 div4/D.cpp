#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
void solve(){
    cin>>n>>k;
    int arr[n];

    bool check=true;
  
    for(int i=0;i<n;i++){
        cin>>arr[i];
       
        arr[i]=arr[i]%k;
    }
   
   
     sort(arr,arr+n);
     int mini=arr[n-1]-arr[0];
     for(int j=0;j<n-1;j++){
        mini=min(mini,arr[j]+k-arr[j+1]);
      
     }
     cout<<mini<<endl;
      
    
    
   

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
