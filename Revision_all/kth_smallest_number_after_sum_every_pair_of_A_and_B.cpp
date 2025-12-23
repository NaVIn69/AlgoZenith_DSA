#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we have two array A and B , we have to form C array such that C[k]=A[i]+B[j] , find kth smallest number 
int n,m,k;
vector<int>arr,brr;

bool check(int mid){
     int cnt=0;
     for(int i=0;i<n;i++){
        if(arr[i]>mid) break;
        int rem=mid-arr[i];
        int idx=upper_bound(brr.begin(),brr.end(),rem)-brr.begin();
        cnt+=idx;
        if(cnt>=k) return true;
     }
     return cnt>=k; 
}


void solve(){
 cin>>n>>m>>k;
 arr.resize(n+1);
 brr.resize(m+1);
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 for(int j=0;j<m;j++){
    cin>>brr[i];
 }
 if(n>m){
    swap(n,m);
    swap(arr,brr);
 }
 int l=arr[0]+brr[0];
 int h=arr[n-1]+brr[n-1];
 while(l<=h){
    int mid=(l+(h-l))/2;
    if(check(mid)){
        // number of element <=mid should be greater than >=k
        ans=mid;
        h=mid-1;
    }else{
        l=mid+1;
    }
 }

}
signed main(){
    solve();
}