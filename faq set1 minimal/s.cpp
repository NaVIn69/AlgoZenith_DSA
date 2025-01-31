#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    int arr[n];
    // one pointer represent the first one 
    // 2nd pointer represent the first zero
    int f_1=INT_MAX;
    int f_0=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
  
   int zeroptr=0;
   int ptr=0;
   while(ptr<n&&zeroptr<n){
      if(arr[ptr]==0){
          swap(arr[ptr],arr[zeroptr]);
          ptr++;
          zeroptr++;
      }else if(arr[ptr]==1){
           ptr++;
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





















/*

int i=0;
  int j=1;
  while(i<n&&j<n){
    cout<<"pointer"<<" "<<i<<" "<<j<<endl;
    if(arr[i]==1&&arr[j]==0){
      swap(arr[i],arr[j]);
      i++;
      j++;
      continue;
    }
    if(arr[i]==0){
      i++;
    }
    if(j<i){
      if(arr[j]==0){
        j++;
      }
    }
    if(arr[j]==1){
    
      j++;
    }

  }

*/