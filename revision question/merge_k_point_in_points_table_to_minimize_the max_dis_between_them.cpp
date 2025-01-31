#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];
bool check(int mid){
    int cnt=0;
    for(int i=1;i<n;i++){
        int d=arr[i]-arr[i-1];
        cnt+=(((d+mid-1)/mid)-1);

    }
    // cout<<cnt<<endl;
    return cnt<=k;
}
void solve(){
    cin>>n>>k;
    int l=0;
    int h=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i) h=max(h,arr[i]-arr[i-1]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    int ans=0;
    // cout<<h<<endl;
    if(k==0){
        cout<<h<<endl;
        // return;
    }else 
    if(h==1){
        cout<<"1"<<endl;
        // return ;
    }else{
    
    while(l<=h){
        int mid=(l+h)/2;
        // cout<<mid<<endl;
        if(check(mid)){
             ans=mid;
             h=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    }

}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}