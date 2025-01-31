#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];
bool check(int mid){
   if(arr[mid]<arr[0]){
    return 1;
   }
   return 0;
}
void solve(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0;
    int h=n-1;
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
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}