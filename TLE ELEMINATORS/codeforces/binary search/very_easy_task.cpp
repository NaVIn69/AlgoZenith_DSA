#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,x,y;

bool check(int mid){
    // can we make n copies in that time 
    // we have one original copies 
    int time=min(x,y); // time 
    if(mid<time) return false;
  // copies 
    // from 1ere they both run simulatenously
    int rem_time=mid-time;
    if(rem_time<0) return false;
   int cnt=1+((rem_time/x)+(rem_time/y));
    if(cnt>=n) return true;
    return false;

   
}
void solve(){
  cin>>n>>x>>y;
  if (n == 1) {
    cout << 0 << "\n";
    
}
  int l=1;
  int h=n*(max(x,y));
  int ans=-1;
  while(l<=h){
     int mid=(l+h)/2;
    //  cout<<mid<<endl;
     if(check(mid)){
        // cout<<"mid " <<mid<<endl;
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
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}