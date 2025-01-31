/*
You are given an array A of size N.
 In one operation you can select any non-decreasing subarray and increment all the elements in the subarray by one.
 Your goal is to make the whole array non-decreasing in minimum operations.

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }

   // here we have been find the next greater element 
//    int next_g[n];
//    stack<int>st;
//    for(int i=n-1;i>=0;i--){
//      while(!st.empty()&&arr[st.top()]<arr[i]){
//         st.pop();
//      }
//      if(st.empty()){
//         // maximum element hai
//         next_g[i]=n;
//      }else{
//         next_g[i]=st.top();
//      }
//      st.push(i);
//    }

   // in next_g array has the next greater than equal to element
   int cnt=0;
   int pre[n]={0};
   for(int i=1;i<n;i++){
    if(arr[i-1]>arr[i]){
        cnt+=arr[i-1]-arr[i];
    }
}
cout<<cnt<<endl;
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}