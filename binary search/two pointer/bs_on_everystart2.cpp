// here we are using the sliding window to find the number of zero 

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n,k;
int a[100100];
int pre[100100];
bool check(int mid){
    int cnt_0=0;
    // here we are counting the number of zero in the mid length subbarray
    for(int i=0;i<mid;i++){
        if(a[i]==0) cnt_0++;
    }
    if(cnt_0<=k) return true;
    for(int i=0;i<n-mid;i++){
        if(a[i+mid]==0) cnt_0++;
        if(a[i]==0) cnt_0--;
        if(cnt_0<=k) return true;
    }
    return false;
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        pre[i]=a[i];
        if(i) pre[i]+=pre[i-1];
    }
    // here we do the binary search on length
    int l=1;
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
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    while(t--){
        solve();
    }
}