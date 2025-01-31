#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];
bool check(int mid){
// mid is the length of subarray 
// we have to every subarray which length is mid
int cnt=0;
   for(int i=0;i<mid;i++){
      if(arr[i]==0) cnt++; 
   }
   if(cnt<=k) return 1;
   for(int i=0;i<n-mid;i++){
       if(arr[i]==0) cnt--;
       if(arr[i+mid]==0) cnt++;
       if(cnt<=k) return 1;
   }
   return 0; 
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    // bs on length
    int l=0;
    int h=n;
    int ans=0;
    while(l<=h){
        int mid=(l+h)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    cout<<ans<<endl;

}
signed main(){
    solve();
}