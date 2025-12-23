#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,w,h;
// int arr[100100];
bool check(int mid){
     return (mid/w)*(mid/h)>=n;
}


void solve(){
  cin>>w>>h>>n;
  int low=0;
  int high=1;
  while(check(high)==false){
      high=high*2;
  }
 

  int ans=0;
  while(low<=high){
     int mid=low+(high-low)/2;
     if(check(mid)){
        ans=mid;
        high=mid-1;
     }else{
        low=mid+1;
     }
  }
  cout<<ans<<endl;
 


}
signed main(){
    solve();
}