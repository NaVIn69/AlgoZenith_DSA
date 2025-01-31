// here we are finding the maximum length subbaray with all ones in <=k flips of zero
// here we are doing the binary search on length which statisfy the condition
// here we are using the prefix array to find the number of zero
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n,k;
int a[100100];
int pre[100100];
int numzero(int l,int r){
    return (r-l+1)-( pre[r]-(l>0?pre[l-1]:0));
}
bool check(int mid){
    int ans=INT_MAX;
    for(int i=0;i<n-mid;i++){
        int x=numzero(i,i+mid-1);
        ans=min(ans,x);
        if(ans<=k) return true;
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