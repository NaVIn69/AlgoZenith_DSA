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
   int sum=0;
   int maxi=-1e9;
   for(int i=0;i<n;i++){
       sum+=arr[i];
       if(sum>maxi){
        maxi=sum;
       }
       if(sum<0){
        sum=0; // start new subarray sum from next index 
       }
   }
   cout<<maxi<<endl;
}
signed main(){
    solve();
}
