#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];
void solve(){
 cin>>n;
 for(int i=0;i<n;i++){
     cin>>arr[i];
 }
  /// first count 0,1,2 and place all the zero in starting then one then two
  // here we can two thing 
  int low=0,mid=0,high=n-1;
  while(mid<=high){
      if(arr[mid]==0){
          swap(arr[low],arr[mid]); 
          low++;
          mid++;
      }else if(arr[mid]==2){
           swap(arr[mid],arr[high]);
           high--;
      }else if(arr[mid]==1){
        mid++;
      }
  }
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;

}
signed main(){
    solve();
}