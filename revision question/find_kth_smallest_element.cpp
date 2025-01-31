#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m,k;
int arr[100100],brr[100100];

bool check(int mid){
   int cnt=0;
   for(int i=0;i<n;i++){
   
      int rem=mid-arr[i];
      if(rem<0) break;
      int index=upper_bound(brr,brr+m,rem)-brr;
      cnt+=index;
      if(cnt>=k) return true;
   
   }
   return cnt>=k;
}
void solve(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int j=0;j<m;j++){
        cin>>brr[j];
    } 
    sort(arr,arr+n);
    sort(brr,brr+m);
    int ans=0;
    int l=arr[0]+brr[0];
    int h=arr[n-1]+brr[m-1];
    while(l<=h){
        int mid=(l+h)/2;
        if(check(mid)){
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