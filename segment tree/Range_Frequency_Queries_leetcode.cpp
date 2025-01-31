#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int arr[100100];
int n,q;


void solve(){
    cin>>n>>q;
    map<int,vector<int>>mpp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mpp[arr[i]].push_back(i);
    }
    while(q--){
        int l,r,val;
        cin>>l>>r>>val;
        vector<int>idx=mpp[val];
        int upper_idx=upper_bound(idx.begin(),idx.end(),r)-idx.begin();
        int lower_idx=lower_bound(idx.begin(),idx.end(),val)-idx.begin();
        cout<<(upper_idx-lower_idx+1)<<endl;
    }


}
signed main(){
    solve();
}