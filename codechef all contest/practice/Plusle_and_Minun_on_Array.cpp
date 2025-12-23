#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n;
    cin>>n;
    int arr[n+1];
    int mini=INT_MAX;
    int maxi=INT_MIN;
    int sum_odd=0;
    int sum_even=0;
    for(int i=1;i<=n;i++){
         cin>>arr[i];
   
        if(i%2){
           mini=min(abs(arr[i]),mini);
           sum_odd+=abs(arr[i]);
        }else{
            maxi=max(abs(arr[i]),maxi);
            sum_even+=abs(arr[i]);
        }
    }
    if(maxi>=mini){
    sum_odd=sum_odd-mini+maxi;
    sum_even=sum_even-maxi+mini;
    }
    cout<<sum_odd-sum_even<<endl;


    

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