#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m,k;
int arr[100100];
int brr[100100];
bool check(int mid){
   int cnt=0;
    for(int i=0;i<m;i++){
        int rem=mid-brr[i];
        int index=upper_bound(arr,arr+n,rem)-arr;
        cnt+=(index);
    }
  
    if(cnt>=k) return 1;
    return 0;
}
void solve(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<m;i++) cin>>brr[i];
    sort(arr,arr+n);
    sort(brr,brr+m);
    int l=arr[0]+brr[0];
    int h=arr[n-1]+brr[m-1];
    int ans=-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(check(mid)){
             // here mid is my x arr[i]+brr[j]<=x
             ans=mid;
            //  cout<<ans<<endl;
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