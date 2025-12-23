#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n;
int arr[100100];
void solve(){
  cin>>n;
  vector<int>v;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    v.push_back(arr[i]);
    if(i){
        arr[i]+=arr[i-1];
    }
  }
  sort(v.begin(),v.end());
  for(int i=1;i<n;i++){
    v[i]+=v[i-1];
  }
  int m;
  cin>>m;
  while(m--){
    int ch,l,r;
    cin>>ch>>l>>r;
    if(ch==1){
       l--,r--;
       if(l==0){
        cout<<arr[r]<<endl;
       }else{
        cout<<arr[r]-arr[l-1]<<endl;
       }
    }else{
        l--,r--;
        if(l==0){
            cout<<v[r]<<endl;
           }else{
            cout<<v[r]-v[l-1]<<endl;
           }


    }
  }


}
signed main(){
    solve();
}