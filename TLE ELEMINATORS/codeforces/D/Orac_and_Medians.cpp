#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

void solve(){
  int n,k;
  cin>>n>>k;
  vector<int>arr(n);
  int zero=0;
  for(int i=0;i<n;i++){
     cin>>arr[i];
      if(arr[i]==k){
        zero++;
        arr[i]=0;
      }else
      if(arr[i]>=k){
        arr[i]=1;
      }else{
        arr[i]=-1;
      }
  }
  // here we have placed the value comparing with medium 
  // then we have to compare with i , i+1, i+2 , if two of element is greater than equal to zero then here we can make that element into 

if(zero==0){
    cout<<"no"<<endl;
    return;
}  
if(zero>n/2){
    cout<<"yes"<<endl;
    return ;
}

for(int i=0;i<n-1;i++){
    if(arr[i]>=0&&arr[i+1]>=0){
        cout<<"yes"<<endl;
        return ;
    }
}
for(int i=0;i<n-2;i++){
    if(arr[i]>=0&&arr[i+2]>=0){
        cout<<"yes"<<endl;
        return;
    }
}
cout<<"no"<<endl;



}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}