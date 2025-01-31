#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// void print(int n){
//     for(int i=31;i>=0;i--){
//         if((n>>i)&1){
//             cout<<"1";
//         }else{
//             cout<<"0";
//         }
//     }
//     cout<<endl;
// }
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int i =0;i<n;i++){
        ans=ans^arr[i];
    }
    cout<<ans<<endl;
}
signed main(){
    solve();
}