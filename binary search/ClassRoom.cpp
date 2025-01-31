#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n,k;
int a[100100];
bool check(int x){
       int needed=1;
       int f_dist=a[0];
       for(int i=1;i<n;i++){
              if(a[i]>=f_dist+x){
                     needed++;
                     f_dist=a[i];
              }
       }
       return needed>=k;

}
void solve(){
    //   int n,k;
       cin>>n>>k;
      // int a[n];
       int max_d=0;
       for(int i=0;i<n;i++){
              cin>>a[i];
            
       }
       sort(a,a+n);
      
       int l=1;
       int h=a[n-1]-a[0];
       int ans=1;
       while(l<=h){
              int mid=l+(h-l)/2;
              if(check(mid)==1){
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