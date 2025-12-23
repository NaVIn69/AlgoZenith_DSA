#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n;
int arr[200200];
int brr[200200];

void solve(){
  cin>>n;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
for(int i=0;i<n;i++){
    cin>>brr[i];
}
// first find the first mismatch from left side and right mismatch from right side
 int l=0,r=n-1;
 int left_mis=-1,right_mis=-1;
 while(l<=r){
    if(arr[l]==brr[l]){
        l++;
    }else{
        left_mis=l;
    }
    if(arr[r]==brr[r]){
        r--;
    }else{
       right_mis=r;
    }
    if(left_mis!=-1&&right_mis!=-1){
        break;
    }
 }
 // from l,r we hvae to extend the on the both side 
  while(l>0&&brr[l-1]<=brr[l]) l--;
  while(r<n-1&&brr[r]<=brr[r+1])r++;
  cout<<l+1<<" "<<r+1<<endl;

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}