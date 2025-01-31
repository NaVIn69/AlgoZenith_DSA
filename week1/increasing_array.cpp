#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(i==n-1){
            continue;
        }
        if(a[i]<=a[i+1]){
            continue;
        }else{
         cnt+=a[i]-a[i+1];
         a[i+1]=a[i];
        }

    }
    cout<<cnt<<endl;

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}