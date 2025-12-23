#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];
bool check(int mid){
    // here mid is the my maximum distance between after placing k point
    int needed_points=0;
    for(int i=1;i<n;i++){
        int dis=(arr[i]-arr[i-1]);
        needed_points+=((dis-mid+1)/mid);
        if(needed_points<=k){
            needed_points+=((dis+mid-1)/mid);
        }else{
            return 0;
        }
    }
    retrun 1;
}

void solve(){
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  sort(arr,arr+n);
  int l=1,int h=arr[n-1]-arr[0];
  int ans=l;
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
signed  main(){
    solve();
}