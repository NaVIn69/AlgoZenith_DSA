#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

int n,x;
int arr[100100];

bool check_lower_bound(int mid){
    if(arr[mid]<x) return 0;
    else return 1;
}
bool check_upper_bound(int mid){
    if(arr[mid]<=x) return 0;
    else return 1;
}

void solve(){
  cin>>n;
 pair<int,int>brr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
    brr[i]={arr[i],i};
  }

  // lowerbound -> just greater than or eqaul to x
  sort(brr,brr+n);
  int l=0,h=n-1;
  int ans=-1;
  while(l<=h){
    int mid=l+(h-l)/2;
    if(check_lower_bound(mid)){
        ans=mid;
      h=mid-1;
    }else{
        l=mid+1;
    }
  }
  cout<<ans<<end;

}
signed main(){
    solve();
}