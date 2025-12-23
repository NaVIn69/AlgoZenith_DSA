#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define endl "\n"

int n;
int arr[200200];
int brr[200200];
void solve(){
    cin>>n;
   for(int i=0;i<n;i++){
    cin>>arr[i];
   } 
  multiset<int>mt;
   for(int i=0;i<n;i++){
      cin>>brr[i];
      mt.insert(brr[i]);
   }
  
   int c[n]={0};
//    auto it=mt.begin();
   for(int i=0;i<n;i++){
       int rem=n-arr[i];
       int rem2=*mt.begin(); // starting value 
       auto it=mt.lower_bound(rem);
       if(it==mt.end()){
          // it better to place the minimum element 
          c[i]=(rem2+arr[i])%n;
          mt.erase(mt.begin());
          continue;
       }
       // here we have to place wither rem2 , or *it to make
       int add1=(arr[i]+*it)%n;
       int add2=(arr[i]+rem2)%n;
       int mini=min(add1,add2);
       if(mini==add1){
        c[i]=add1;
        mt.erase(it);
       }else{
        c[i]=add2;
        mt.erase(mt.begin());
       }
   }
   for(int i=0;i<n;i++){
    cout<<c[i]<<" ";
   }
   cout<<endl;

}
int main(){
    solve();
}