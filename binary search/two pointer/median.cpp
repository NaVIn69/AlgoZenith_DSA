#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];

bool check(int mid){
 
    // here we have to count the for every element
   int head=-1;
   int tail=0;
   // data structure 
   int cnt=0;
   int sum=0;
   while(tail<n){
  // eat as many element you can eat
    while(head+1<n&&sum+arr[head+1]<=mid){
       sum+=arr[head+1];
        head++;
    }

    int len=head-tail+1;
    cnt+=len;
    if(cnt>=k) return 1;
    if(tail<=head){
        sum-=arr[tail];
        tail++;
    }else{
        tail++;
        head=tail-1;
    }
   }
   return cnt>=k;
    
}
void solve(){

    cin>>n;
    int mini=1e9;
    int sum=0;
int lo=(n*(n+1))/2;
k=(lo+1)/2;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        mini=min(mini,arr[i]);
        sum+=arr[i];
    }
    int l=mini;
    int h=sum;
    int ans=l;
    while(l<=h){
        int mid=l+(h-l)/2;
      
        if(check(mid)){
            
            ans=mid;
            h=mid-1;
        }else{
       
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    

}
signed main(){
  
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}