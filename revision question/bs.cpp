// lower bound
// for upper bound we have to change the arr[i]>x
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,x;
int arr[1001000];
bool check(int mid){
    /*
    upper bound
    if(arr[mid]>x){
        return 1;
    }
    return 0;
    */
  
   /*
    rotated array
   if(arr[mid]<arr[0]){
    return 1;
   }
   return 0;

   */
/*
  bitonic array (peak finding )
  if(mid==n-1) return 1;
  if(arr[mid+1]>=arr[mid]) return 0;
  return 1;
*/
 
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // arr[i]>=x
    // we have to find the first element which is just greater than x
    int l=0,h=n-1,ans=n;
    while(l<=h){
        int mid=(l+h)/2;
        if(check(mid)){
            ans=mid;
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;



}
signed main(){
    solve();
}
