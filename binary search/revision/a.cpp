#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,x;
int arr[100100];

// lower bound check
bool check(int mid){
   if(arr[mid]<x) return false;
   return true;
}

// upper bound check
bool check_upper(int mid){
    if(arr[mid]<=x) return false;
    return true;
}
void solve(){
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    // lower bound
    int l=0;
    int h=n-1;
    int ans=-1;
    while(l<=h){
        int mid=l+(h-l)/2; // (l+h)/2;
        if(check_upper(mid)){
           ans=mid;
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;

}
signed main(){
    solve();
}