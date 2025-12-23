#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        int idx=lower_bound(arr,arr+n,x)-arr;
        cout<<idx+1<<endl;
    }
}
signed main(){
    solve();
}