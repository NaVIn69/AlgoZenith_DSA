#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];

int partition_algo(int left,int right){
   // here in the left of pivot val me sare smallest value 
   int pivot_val=arr[right];
   int l=left;
   int r=right-1;
   while(l<=r){
      if(arr[l]>pivot_val&&arr[r]<pivot_val){
        swap(arr[l],arr[r]);
        l++;
        r--;
      }
      if(arr[l]<=pivot_val){
        l++;
      }

      if(arr[r]>=pivot_val){
        r--;
      }
   }
   swap(arr[l],arr[right]);
   return left;
}

void solve(){
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int left=0;
int right=n-1;
int kth=0;
while(1){
    int idx=partition_algo(left,right);
    if(idx==k-1){
        kth=arr[idx];
        break;
    }
    if(idx<k-1){
        left=idx+1;
    }else{
        right=idx-1;
    }

}
cout<<kth<<endl;


}
signed main(){
    solve();
}