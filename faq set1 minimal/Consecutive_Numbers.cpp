#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mpp[arr[i]]++;
    }
    if(n%k){
        cout<<"No"<<endl;
        return;
    }
    for(auto v:mpp){
        if(v.second==0) continue;
        //here we got the starting point
        // we are substracting the starting point freq
        for(int i=1;i<k;i++){
            mpp[v.first+i]-=v.second;
            //here we got our starting point
            if(mpp[v.first+i]<0){
                cout<<"No"<<endl;
             return;
            }
            
        }
    }
   
    cout<<"Yes"<<endl;
    
 }
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
