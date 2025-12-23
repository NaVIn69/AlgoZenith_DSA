#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[200200];
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];        
    }
    int maxi=-1e9;
    int sum=arr[0];
    maxi=max(sum,maxi);
    for(int i=1;i<n;i++){
        // parity changes then we extend that list
        if((abs(arr[i])%2)!=(abs(arr[i-1])%2)){
            sum+=arr[i];
        }else{
            sum=arr[i];
        }
        // starting fresh is better than extension
        
        sum=max(sum,arr[i]);
        maxi=max(maxi,sum);
        // cout<<sum<<" "<<maxi<<endl;
     }
        cout<<maxi<<endl;

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}