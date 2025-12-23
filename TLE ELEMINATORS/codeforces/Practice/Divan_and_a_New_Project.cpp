#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>>arr(n);
    int brr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second=i;
        brr[i]=arr[i].first;
    }
    sort(arr.rbegin(),arr.rend());
    // max element at the id
    map<int,int>mpp;// val -> x
    int x_pos=0; // owner
    int x_neg=0;
    int tot=0;
    for(int i=0;i<n;i+=2){
        x_pos++;
         mpp[arr[i].second]=x_pos;
         tot+=(2*(x_pos)*arr[i].first);
         if(i+1!=n){
            x_neg--;
            mpp[arr[i+1].second]=x_neg;
            tot+=(2*abs(x_neg)*arr[i+1].first);
         }
    }
    cout<<tot<<endl;
    cout<<0<<" ";
    for(int i=0;i<n;i++){
         cout<<mpp[i]<<" ";
    }
    cout<<endl;



}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}