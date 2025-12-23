#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define endl "\n"
int n;
int medium;
pair<int,int>arr[100100];

ld max(ld a,ld b){
    if(a>=b){
        return a;
    }
    return b;
}
ld min(ld a,ld b){
    if(a<=b){
        return a;
    }
    return b;
}

bool check(ld mid){
   // can we reach at the medium in the that time
   ld L = -numeric_limits<ld>::infinity();
    ld R =  numeric_limits<ld>::infinity();
    for(int i=0;i<n;i++){
        ld l=arr[i].first*1.0L-mid*arr[i].second*1.0L; 
        ld r=arr[i].first*1.0L+mid*arr[i].second*1.0L;
        L=max(L,l);
        R=min(R,r);
    }
    return L<=R;
}

void solve(){
  cin>>n;
  int mini=1e9;
  int idx=0;
  for(int i=0;i<n;i++){
     cin>>arr[i].first>>arr[i].second;
    
  }
  sort(arr,arr+n);
  // here min(arr[i]-x) at the medium
  // in time t , here we have range where all interval meets
  // max(arr[i].first-arr[i].second*t)<= min(arr[i].first+)

  // search space 
  ld l=0.0L;
  ld h=1.0L;
   while(check(h)==false){
      h=h*2.0L;
   }

  ld EPS=1e-8;
  ld ans=h;
  while(abs(h-l)>=EPS){
     ld mid=(l+h)*0.5L;
     if(check(mid)){
        ans=mid;
        h=mid;
     }else{
        l=mid;
     }
  }
  cout<<fixed<<ans<<setprecision(6)<<endl;

}
int main(){
    solve();
}