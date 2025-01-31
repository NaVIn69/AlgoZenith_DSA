#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];
bool check(int mid){
    // can we place the <=k point with distance of <=x 
    int num_points=0;
    for(int i=1;i<n;i++){
        int d=arr[i]-arr[i-1];
        num_points+=((d+mid-1)/mid);
        if(num_points>k) return 0;
    }
    return true;
}
void solve(){
   cin>>n>>k;
   int l=0;

   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   sort(arr,arr+n);
   int h=0;
   for(int i=1;i<n;i++){
        h=max(h,abs(arr[i]-arr[i-1]));
   }
   int ans=0;
   while(l<=h){
    int mid=l+(h-l)/2;
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