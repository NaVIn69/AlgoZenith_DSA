#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    int maxi=0;
    int index=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxi=max(arr[i],maxi);
        if(arr[i]==maxi){
            index=i;
        }
    }
    if((index>=0&&index<k)||(index<n&&index>=n-k)){
        int index=
    }
    int cnt=0;
    int index_last=0;
    int index_first=0;
    if(k%2){
      index_last=index-(k-1)/2;
      index_first=index+(k-1)/2;
    }else{
        index_last=index-(k-1)/2;
        index_first=index+(k-1)/2;
    }
    for(int i=index;i>=0;){
        if(i+1>=k){
           cnt++;
          i=i-(k-1);
        }else{
            cnt++;
            break;
        }
    }
    for(int i=index;i<n;i++){
        if(i+k-1<n){
           cnt++;
           i=i+(k-1);
        }else{
            cnt++;
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