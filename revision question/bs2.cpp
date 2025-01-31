#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];
bool check(int mid){
    if(mid==n-1) return 1;
    if(arr[mid]<arr[mid+1]){
        return 1;
    }
    return 0;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
  int ans=n;
  int l=0;
  int h=n;
  while(l<=h){
    int mid=l+(h-l)/2;
    if(check(mid)){
        ans=mid;
        h=mid-1;
    }else{
        l=mid+1;
    }
  }
  
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}