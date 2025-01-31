#include<bits/stdc++.h>
using namespace std;
#define int long long 
bool check(int mid,int diff[],int k,int n){
    int needed_points=0;
    for(int i=1;i<n;i++){
        needed_points+=((diff[i]+mid-1)/mid-1);
    }
    return needed_points<=k;
    }
void solve(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=1;
    int h=0;
    int difference[n];
    difference[0]=0;
    for(int i=1;i<n;i++){
        difference[i]=a[i]-a[i-1];
        h=max(h,difference[i]);
    }
    int ans=h;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(check(mid,difference,k,n)){
            ans=mid;
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}