#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,k;
int arr[100100];
bool check(int mid){
    // can we place the cows when they are at max distance of mid
    int cnt=1; // because we have been placed the cow at the arr[0] coordinates , now from here we are moving 
    int placed=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-placed>=mid){
            cnt++;
            placed=arr[i-1];
            if(arr[i]-placed>=mid){
                cnt++;
                placed=arr[i];
            }
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
  int h=0;
  for(int i=1;i<n;i++){
    h=max(h,arr[i]-arr[i-1]);
  }
  h=max(h,arr[n-1]-arr[0]);
  // on these coordinate we have to place the k cows and we have to find the maximum minimum distance between them
  int l=1;
  int ans=1;
  while(l<=h){
    int mid=l+(h-l)/2;
    if(check(mid)){
        // cout<<"mid L"<<mid<<endl;
        ans=mid;
        l=mid+1;
    }else{
       // cout<<"mid R "<<mid<<endl;
        h=mid-1;
        
    }
  }
  cout<<ans<<endl;

}
signed main(){
    solve();
}