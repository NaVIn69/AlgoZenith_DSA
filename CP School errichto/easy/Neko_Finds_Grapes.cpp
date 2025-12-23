#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n,m;
    cin>>n>>m;
    int arr[n],brr[m];
    multiset<int>even,odd;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]&1){
            odd.insert(arr[i]);
        }else{
            even.insert(arr[i]);
        }
    }
    for(int i=0;i<m;i++){
        cin>>brr[i];
    }
    int ans=0;
    for(int i=0;i<m;i++){
        if(brr[i]&1){
           if(!even.empty()){
            ans++;
            even.erase(even.begin());
           }
        }else{
            if(!odd.empty()){
                ans++;
                odd.erase(odd.begin());
            }

        }
        if(even.empty()&&odd.empty()){
            break;
        }
    }
    cout<<ans<<endl;

}
signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}