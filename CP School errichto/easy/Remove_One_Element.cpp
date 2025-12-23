#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[200200];
void solve(){
//   int n;
  cin>>n;
//   int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  // here we have l -> longest inc subarray ending at i
  // here r-> longest subarray starting at i
  vector<int>left(n,1),right(n,1);
  for(int i=1;i<n;i++){
      if(arr[i]>arr[i-1]){
        left[i]=left[i-1]+1;// previous wale ko include kr lenge
      }else{
        // dont increase that single element subarray
      }
  }
  for(int i=n-2;i>=0;i--){
    if(arr[i]<arr[i+1]){
        right[i]=right[i+1]+1;
    }
  }
  // now dont delelete any element find the max length 
//   for(int i=0;i<n;i++){
//     cout<<left[i]<<" ";
//   }
//   cout<<endl;

//   for(int i=0;i<n;i++){
//     cout<<right[i]<<" ";
//   }
//   cout<<endl;

  int ans=0;
  for(int i=0;i<n;i++){
      ans=max(ans,left[i]);
      ans=max(ans,right[i]);
  }
  // here we have bee finout the maximum length subarray end at i and starting from i
  //cout<<ans<<endl;
  for(int i=1;i<n-1;i++){
      // if we are going to delete the ith element then we can extend 
      if(arr[i-1]<arr[i+1]){
          ans=max(ans,left[i-1]+right[i+1]);
      }else{
        ans=max(ans,left[i-1]);
        ans=max(ans,right[i+1]);
      }

  }
  cout<<ans<<endl;

}
signed main(){
    solve();
}