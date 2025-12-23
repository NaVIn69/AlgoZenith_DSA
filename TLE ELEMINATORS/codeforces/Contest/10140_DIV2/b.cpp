#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
   int n,s;
   cin>>n>>s;
   int arr[n];
   int cnt0=0,cnt1=0,cnt2=0,tot=0;
   for(int i=0;i<n;i++){
    cin>>arr[i];
    tot+=arr[i];
    if(arr[i]==0)cnt0++;
    else if(arr[i]==1)cnt1++;
    else if(arr[i]==2)cnt2++;
    
   }

   if(s<tot || s==tot+1){
      for(int i=0;i<cnt0;i++){
        cout<<"0"<<" ";
      }
      for(int i=0;i<cnt2;i++){
        cout<<"2"<<" ";
      }
      for(int i=0;i<cnt1;i++){
        cout<<"1"<<" ";
      }
      cout<<endl;
   }else{
    cout<<"-1"<<endl;
   }
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}