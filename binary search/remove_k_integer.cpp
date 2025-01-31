#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n,k;
int a[1000005];
bool check(int diff[],int mid){
   


}
void solve(){
 cin>>n>>k;
 int a[n],diff[n]={0};
 int maxi=INT_MIN;
 int mini=INT_MAX;
 for(int i=0;i<n;i++){
    cin>>a[i];
    if(i){
         diff[i]=abs(a[i]-a[i-1]);
         maxi=max(diff[i],maxi);

    }
 }
 // here we apply the binary search on ans
 int l=0;
 int h=maxi;
 int ans=0;
 while(l<=h){
    int mid=l+(h-l)/2;
    if(check(diff,mid)){
        ans=mid;
        l=mid+1;
    }else{
        h=mid-1;
    }
 }
 cout<<ans<<endl;
    

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}