#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];
bool check(int mid){
    int student=0;
    for(int i=1;i<n;i++){
        int d=abs(arr[i]-arr[i-1]);
         student+=((d+mid-1)/mid);
         if(student>k) return false;
         if(student<=k) return true;
    }
    return student<=k;
    
}
void solve(){
   cin>>n>>k;
   int maxi=0;
   for(int i=0;i<n;i++){
    cin>>arr[i];
    if(i){
        maxi=max(maxi,abs(arr[i]-arr[i-1]));
    }
   }
//    sort(arr,arr+n);
   int l=0;
   int h=maxi;
   int ans=0;
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
   int t=1;
   cin>>t;
   while(t--){
    solve();
   }
}