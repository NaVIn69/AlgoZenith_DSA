#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"


void solve(){
    int n;
    cin>>n;
    int arr[n];
    int mini=0;
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
       if(arr[i]%2==0){
        mpp[arr[i]]++;
       }     
    }
for(auto x:mpp){
    int cnt=0;
    int val=x.first;
    while(val%2==0){
        cnt++;
        val/=2;
        if(mpp.find(val)!=mpp.end()){
            break;
        }
    }
    mini+=cnt;
}
cout<<mini<<endl;
   
    

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}