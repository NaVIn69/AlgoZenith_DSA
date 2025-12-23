#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"


int n,c;
int arr[200200];
void solve(){
  cin>>n>>c;
  for(int i=0;i<n;i++){
      int x;
      cin>>x;
      arr[i]=x+i+1;
  }
  /*
   5 9
   2 3 1 4 1
   after sorting 
   3,5,4,8,6
   3 4 5 6 8
  */
  sort(arr,arr+n);
  int cnt=0;
  int ans=0;
  for(int i=0;i<n;i++){
      if(ans+arr[i]<=c){
        ans+=arr[i];
        cnt++;
      }else{
        break;
      }      
  }

    cout<<cnt<<endl;
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}