#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
vector<int>arr,brr;
bool check(int x){
    // number of ele is less then <=x is>=k
    int cnt=0;
    for(int i=0;i<n;i++){
     cnt+=upper_bound(brr.begin(),brr.end(),x-arr[i])-brr.begin();
    }
    return cnt>=k;
}
void solve(){
    cin>>n>>m>>k;
    arr.resize(n);
    brr.resize(m);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m;i++){
        cin>>brr[i];
    }
    if(n>m){
        swap(n,m);
        swap(arr,brr);
    }
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    int l=arr[0]+brr[0];
    int h=arr.back()+brr.back();
    int ans=-1;
    while(l<=h){
    int mid=l+(h-l)/2;
    if(check(mid)==1){
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
    // cin>>t;
    while(t--){
        solve();
    }
}