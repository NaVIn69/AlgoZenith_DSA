#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

vector<int>fuck(vector<int>&arr){
     int n=arr.size();
     vector<int>freq(n+2,0);
     for(int x:arr){
        freq[x]++;
     }
     int mex=0;
     while(mex<n+1&&freq[mex]>0){
        mex++;
     }
     // here we get the mex
     vector<int>b(n);
     for(int i=0;i<n;i++){
         int val=arr[i];
         if(val<mex && freq[val]==1){
             b[i]=val; // unique val and less than mex , removing this 
         }else{
            b[i]=mex;
         }
     }
     return b;
}
int sum(vector<int>&arr){
    int s=0;
    for(int x:arr){
        s+=x;
    }
    return s;
}

void solve(){
  int n,k;
  cin>>n>>k;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
     cin>>arr[i];
  }
  vector<int>f=fuck(arr);
  if(f==arr){
      cout<<sum(arr)<<endl;
      return ;
  }
  if(k==1){
     cout<<sum(f)<<endl;
     return ;
  }
  vector<int>f2=fuck(f);
  if(k%2==0){
     cout<<sum(f2)<<endl;

  }else{
    vector<int>f3=fuck(f2);
    cout<<sum(f3)<<endl;
  }


}
signed main(){
   int t=1;
   cin>>t;
   while(t--){
    solve();
   }
}