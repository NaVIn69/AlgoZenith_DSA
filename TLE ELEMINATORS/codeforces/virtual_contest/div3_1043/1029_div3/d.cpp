#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
   int n;
   cin>>n;
   int arr[n+1];
   for(int i=1;i<=n;i++){
        cin>>arr[i];
   }
   // every index
   int d=arr[2]-arr[1];
   for(int i=2;i<=n;i++){
       if(arr[i]-arr[i-1]!=d){
          cout<<"NO"<<endl;
          return ;
       }
   }
//    eq -> a[i]= (n+1)*y +(x+y)*i -> 
   int c=arr[1]-d;
   int den=n+1;
   if(c<0 || c%den!=0){
    cout<<"NO"<<endl;
    return ;
   }
   int y=c/den; // y
   int x=d+y;
   if(x<0){
    cout<<"NO"<<endl;
    return ;
   }

   for(int i=1;i<=n;i++){
      int exp=(n+1)*y+(x-y)*i;
      if(exp!=arr[i]){
        cout<<"NO"<<endl;
    return ;
      }
   }
   cout<<"YES"<<endl;
 
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}