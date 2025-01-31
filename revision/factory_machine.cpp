#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,t;
int arr[200200];
bool check(int mid){
     // can we make t product in time mid using all the machine together
     int cnt=0;
     for(int i=0;i<n;i++){
        cnt+=(mid/arr[i]);
        if(cnt>=t) return true;
     }
     return false;
}

void solve(){
   cin>>n>>t;
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   int l=1;
   int h=1e18;
   int ans=0;
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
    solve();
}