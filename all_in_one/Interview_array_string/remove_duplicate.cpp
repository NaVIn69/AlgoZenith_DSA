#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n;
int arr[100100];
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1){
        return ;
    }
    int l=1,r=1;
    while(l<n&&r<n){
        if(arr[l-1]==arr[r]){
            r++;
        }else{
            arr[l]=arr[r];
            l++;
            r++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}