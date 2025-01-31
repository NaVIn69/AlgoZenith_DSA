//arr[indx]>=x; index=smallest index
#include<bits/stdc++.h>
using namespace std;
int n;
int a[100100];
int check1(int mid,int x){
    if(a[mid]>=x){
        return 1;
    }else{
        return 0;
    }
   }
void solve(){
   cin>>n;
   int x;
   cin>>x;
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
 
   
   int s=0;
   int e=n-1;
   int ans=n; 
   while(s<=e){
    int mid=s+(e-s)/2;
    if(check1(mid,x)==1){
      ans=mid;
      e=mid-1;
    }else{
        s=mid+1;
    }
   }
   
cout<<ans<<endl;
   
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}