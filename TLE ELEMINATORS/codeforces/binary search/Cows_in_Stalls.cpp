#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,k;
int arr[100100];
bool check(int mid){
    // can we place at the at <= mid distance 
    int cnt=1;
    int placed=arr[0];
    for(int i=1;i<n;i++){
         if(arr[i]-placed>=mid){
            cnt++;
            placed=arr[i];
         }
         if(cnt>=k) return true;
    }
    return cnt>=k;
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int l=1;
    int h=arr[n-1]-arr[0];
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