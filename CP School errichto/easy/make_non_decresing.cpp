#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

// here for increasing a to a+1 we in one op
void solve(){
   int n;
   cin>>n;
   int arr[n];
   int tot=0;
   for(int i=0;i<n;i++){
         cin>>arr[i];
         if(i){ 
         if(arr[i]<arr[i-1]){
            arr[i]=arr[i-1];
            tot+=abs(arr[i]-arr[i-1]);
         }
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