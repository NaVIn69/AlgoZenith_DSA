#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    pair<int,int>arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second=i;
    }
    sort(arr,arr+n);
    int prefix[n];
    for(int i=0;i<n;i++){
        prefix[i]=arr[i].first;
        if(i) prefix[i]+=prefix[i-1];
    }
   
    int q;
    cin>>q;
    while(q--){
        int c,k;
        cin>>c>>k;
        map<int,int>mpp;
        int brr[k];
        for(int i=0;i<k;i++){
            int index;
             cin>>index;
             brr[i]=arr[index-1].first;
            
        }
        int cnt=upper_bound(prefix,prefix+n,c)-prefix;
        int remaining=0;
        for(int i=0;i<k;i++){
          int def_idx=lower_bound(arr,arr+n,brr[i])-arr;
          
           
        }
        
    }
    

    

}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}