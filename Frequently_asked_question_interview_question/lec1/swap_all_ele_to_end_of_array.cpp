#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n;
int arr[100100];
void solve(){
  cin>>n;
  int l=1e9;

  for(int i=0;i<n;i++){
    cin>>arr[i];
    if(arr[i]==0){
        l=min(l,i); // first zero 
    }

  }
// int h=0;
//   while(l<n&&h<n){
//     if(arr[h]==0)h++;
//     else{
//         if(l<h){
//         swap(arr[h],arr[l]);
//         l++;
//         h++;
//         }else{
//           h++;
//         }
//     }
//   }

   int zeroptr=0;
   for(int i=0;i<n;i++){
    if(arr[i]!=0){
        if(zeroptr!=i){
            swap(arr[zeroptr],arr[i]);
        }
        zeroptr++;
    }
   }
   
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}