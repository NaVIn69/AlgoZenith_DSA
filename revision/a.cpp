#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,x;
int arr[100100];
bool check(int mid){
     // can we paint the wall in mid time with the help of k painter
     int time=mid;
     int cnt=1;
     for(int i=0;i<n;i++){
        if(time>=arr[i]){
            time-=arr[i];
        }else{
            time=mid;
            if(time>=arr[i]){
                time-=arr[i];
            }
            cnt++;
        }
        if(cnt>x) return false;
     }
     return true;

}

void solve(){
  cin>>n;
  int l=0;
  int h=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    h+=(arr[i]);
    l=max(arr[i],l);
  }  
  cin>>x;
  sort(arr,arr+n);
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
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}