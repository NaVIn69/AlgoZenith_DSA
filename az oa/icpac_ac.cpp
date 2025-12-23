#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>v2(v.begin(),v.end());
    sort(v2.begin(),v2.end());
    int prev=0;
    int ans=0;
    int prev_index=0;
    for(int i=0;i<n;i++){
        // here we are finding that how many element we need to put in front of that element and counting that
        if(v[i]>prev){
        int cnt=lower_bound(v2.begin(),v2.end(),v[i])-v2.begin();
        if(i!=cnt){
        if(ans==0){
         ans=ans+(cnt-ans);
        }else{
            ans=ans+(cnt-prev_index-1);
        }
        }
        prev_index=cnt;
       
        // if(ans==0){
        // ans=ans+(cnt-ans);
        // }else{
        //     ans=ans+(cnt-ans-1);
        // }
        
     
        prev=v[i];
        }else if(v[i]<prev){
            continue;
        }
       


    }
    cout<<ans<<endl;

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}