#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    int arr[n];
    map<int,pair<int,int>>mpp;
    for(int i=0;i<n;i++){
         cin>>arr[i];
         mpp[arr[i]].first++;
         mpp[arr[i]].second=i; // index is present 
    }
    // most frequent elment
    int ele=-1;
    int maxi=0;
    int idx=-1;
    for(auto v:mpp){
        if(v.second.first>maxi){
            ele=v.first;
            idx=v.second.second;
            maxi=v.second.first;
        }
    }
    // cout<<ele<<" "<<maxi<<" "<<idx<<endl;
    // left side
    cout<<n-maxi<<endl;
    int l=idx;
    int r=idx;
    idx--;
    while(idx>=0){
        if(arr[idx]<ele){
            // first operationa add (idx,l)
            cout<<1<<" "<<idx+1<<" "<<l+1<<endl;
        }else if(arr[idx]>ele){
            // 2nd op (idx,l)
            cout<<2<<" "<<idx+1<<" "<<l+1<<endl;
        }
        idx--;
        l--;
    }
    // right side
    idx=r+1;
    int right=r;

    while(idx<n){
        if(arr[idx]<ele){
            // first operationa add (idx,l)
            cout<<1<<" "<<idx+1<<" "<<right+1<<endl;
        }else if(arr[idx]>ele){
            // 2nd op (idx,l)
            cout<<2<<" "<<idx+1<<" "<<right+1<<endl;
        }
        idx++;
        right++;
    }

}
signed main(){
  solve();
}