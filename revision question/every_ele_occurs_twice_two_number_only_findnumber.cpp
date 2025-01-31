#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   int x=0;
   for(int i=0;i<n;i++){
    x=x^arr[i];
   }
   cout<<x<<endl;
   int set_bit=x&(~(x-1));
   cout<<set_bit<<endl;
   // set_bit tells me about the right_most set bit
   int a=0,b=0;
   // 
   for(int i=0;i<n;i++){
      if(set_bit&arr[i]){
        a =a^arr[i];
      }else{
        b=b^arr[i];
      }
   }
   cout<<a<<" "<<b<<endl;
}
signed main(){
   solve();
}