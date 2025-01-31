#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
     int n;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++) cin>>arr[i];
     int ans=0;
     for(int i=0;i<32;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=(arr[j]&(1<<i));
        }
        if(sum%3){
            ans=ans|(1<<i);
        }
     }
     cout<<ans<<endl; 
}
signed main(){
    solve();
}