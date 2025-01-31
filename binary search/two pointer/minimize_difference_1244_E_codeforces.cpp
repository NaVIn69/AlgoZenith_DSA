#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];
int pref[100100];
bool cost(int l,int r){
      // cost for right side
      if(l<0) l=0;
      int right_idx=upper_bound(arr,arr+n,r)-arr;
      int num_ele=n-right_idx;
      int val=pref[n-1]-pref[right_idx-1]-num_ele*r;
      cout<<"right_val"<<" "<<val<<" "; 
      int left_idx=lower_bound(arr,arr+n,l)-arr;
      val=(left_idx+1)*arr[left_idx]-pref[left_idx];
      cout<<"left_val"<<" "<<val<<" "<<endl;
      
      return 0;
}
bool check(int mid){
    // here for every element we have to check can we put all the element in the range [l....r]
    for(int i=0;i<n;i++){
        bool cost1=cost(arr[i],arr[i]+mid);
        if(cost1) return 1;
        bool cost2=cost(arr[i]-mid,arr[i]);
        if(cost2) return 1;  
    }
    return 0;

}
void solve(){
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    pref[i]=arr[i];
    if(i){
        pref[i]+=pref[i-1];
    }
  }
  sort(arr,arr+n);

  int l=0;
  int h=arr[n-1]-arr[0];
  int ans=0;
  while(l<=h){
    int mid=l+(h-l)/2;
    // cout<<"mid"<<" "<<mid<<" ";
    if(check(mid)){
        ans=mid;
        h=mid-1;
    }else{
        l=mid+1;
    }
     cout<<"mid"<<" "<<mid<<" "<<"ans"<<" "<<ans<<" "<<endl;
  }
  cout<<ans<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}