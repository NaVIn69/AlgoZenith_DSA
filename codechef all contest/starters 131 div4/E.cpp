
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int s=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]==0||arr[i]==1||s<=1){
             s=(s+arr[i])%mod;
        }else{
            s=(s*arr[i])%mod;
        }
  
    }
    cout<<s%mod<<endl;

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