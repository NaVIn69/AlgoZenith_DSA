#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n;
    cin>>n;
    int arr[n];
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i!=0||i!=n-1){
        mini=min(arr[i],mini);
        }
    }
    if(arr[0]!=arr[n-1]){
        cout<<"NO"<<endl;
        return;
    }
    bool ans=true;
    for(int i=1;i<n-1;i++){
        if(arr[i]<arr[0]||arr[i]<arr[n-1]){
            cout<<"NO"<<endl;
            return;
          
        }
    }
    cout<<"YES"<<endl;

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
