#include<bits/stdc++.h>
using namesapce std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    int arr[n],brr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>brr[i];
    }
    int prev=0;
    bool check=true;
    int crr[n];
    for(int i=0;i<n;i++){
        int diff=brr[i]-arr[i];
        if(diff<0){
            cout<<"NO"<<endl;
            return;
        }
        crr[i]=diff;
    }
    for(int i=0;i<n;i++){
        if(check&&crr[i]==0){
            continue;
        }else if(crr[i]>0){
            check=false;
        }else if(check==false&&crr[i]==0){
            continue;
        }else {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}