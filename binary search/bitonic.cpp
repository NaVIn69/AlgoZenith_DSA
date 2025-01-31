#include<bits/stdc++.h>
using namespace std;
int check(int mid,int*a,int n,int k){
    if(a[mid]<=k){
        return 1;
    }else{
        return 0;
    }
}
int bitonic(int*a,int k,int n ){
    int s=0;
    int e=n-1;
    int ans=0;
    while(s<=n){
     int mid=s+(e-s)/2;
     if(check(mid,a,n,k)==1){
        ans=mid;
        e=mid-1;
     }else{
        s=mid+1;
     }
    }
}
void solve(){
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    while(q--){
        int k;
        cin>>k;
        int ans=bitonic(a,k,n);
        cout<<ans+1<<endl;
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}