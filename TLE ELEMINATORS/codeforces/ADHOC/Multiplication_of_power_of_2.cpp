#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,q;
int arr[200200];
void solve(){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max_x=32;
   while(q--){
    int x;
    cin>>x;
    
     if(x>max_x){
        continue;
     }
     for(int i=0;i<n;i++){
        if((arr[i]&((1<<x)-1))==0){
           arr[i]+=((1<<x)-1);
        }
     }
     max_x=x;

   } 
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
   

}
signed main(){
   solve();
}