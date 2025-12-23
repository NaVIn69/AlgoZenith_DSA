#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
int arr[100];
void solve(){
 cin>>n;
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 // here we have 2^n subset
 for(int mask=0;mask<(1<<n);mask++){
      cout<<mask<<" : "; // here each mask represent set of unique number 
      for(int i=0;i<n;i++){
           if(((mask>>i)&1)==0){ // checking ith bit of the mask
              cout<<arr[i]<<" ";
           }
      }
      cout<<endl;
 }
 cout<<endl;
 // submask
  for(int mask=0;mask<(1<<n);mask++){
       cout<<"mask"<<" "<<mask<<" ; "<<endl;;
      for(int submask=mask;submask>0;submask=(submask-1)&mask){
         cout<<"submask"<<" "<<submask<<" : ";
             for(int i=0;i<n;i++){
                   if((submask>>i)&1){
                    cout<<arr[i]<<" ";
                   }
             }
             cout<<endl;
      }
  }
  // here submask is representing the subset of subset


}
signed main(){
    solve();
}