#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we can convert atmost k zero into the one .=, after that we have to find longest subarray
int n,k;
int arr[100100];

void solve(){
cin>>n>>k;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
// two pointer to maintain the window
int head=-1,tail=0;
// data structure to maintain the window proprety 
int cnt0=0;

// answer to store the 
int ans=0;
while(tail<n){
    // eat as many as u can eat 
    while(head+1<n && (arr[head+1]==1 || cnt0<k )){
        head++;
        if(arr[head]==0) cnt0++;
    }
    // store the best length
    int len=head-tail+1;
    ans=max(ans,len);
   // moving the tail one step forward
   if(tail<=head){
      if(arr[tail]==0){
        cnt0--;
      }
      tail++;
   }else{
    tail++;
    head=tail-1;
   }
}
cout<<ans<<endl;


}
signed main(){
    solve();
}