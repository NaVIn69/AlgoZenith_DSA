#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
/*
we have given two array in the  we have find the number of pair in A and B which sum a[i]+b[j]<=x

*/
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int arr[n],brr[m];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int j=0;j<m;j++) cin>>brr[j];
    sort(arr,arr+n);
    sort(brr,brr+m);
    int cnt=0;
    for(int i=0;i<m;i++){
        int rem=k-brr[i];
        int index=upper_bound(arr,arr+n,rem)-arr;
        cnt+=(index-1);
    }
    cout<<cnt<<endl;



}
signed main(){
    solve();
}