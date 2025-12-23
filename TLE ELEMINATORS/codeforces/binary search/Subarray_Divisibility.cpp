#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];
int prefix[100100];
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        prefix[i]=arr[i];
        if(i){ 
            prefix[i]+=prefix[i-1];
        }
    }
    // subarray divisibllity
    for(int i=0;i<n;i++){
        cout<<prefix[i]<<" ";
    }
    cout<<endl;
    int sum=0;
    int cnt=0;
   map<int,int>mpp;
   mpp[sum]=1;
   for(int i=0;i<n;i++){
      sum+=arr[i];
      int rem=sum%n;
      // either add -127-5=-132
      // -127+3 
      cout<<sum<<" "<<rem<<endl;
      if(mpp.find(rem)!=mpp.end()){
         cnt+=mpp[rem];
      }
      mpp[sum%n]++;
   }
   cout<<cnt<<endl;

}
signed main(){
    solve();
}