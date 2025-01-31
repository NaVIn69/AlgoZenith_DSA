#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    int arr[n];
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
       mpp[arr[i]]++;
    }
    int cnt=0;
    for(auto x:mpp){
        if(x.second<x.first){
            cnt+=x.second;
        }else if(x.second>x.first){
            cnt+=(x.second-x.first);
        }
    }
    cout<<cnt<<endl;

}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}