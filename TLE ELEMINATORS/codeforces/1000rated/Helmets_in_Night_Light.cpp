#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool comp(pair<int,int>&a,pair<int,int>&b){
    if(a.first==b.first){
        return a.second>b.second; // maximum calling resident
    }
    return a.first<b.first; // increasing price 
}
void solve(){
    int n,p;
    cin>>n>>p;
    pair<int,int>arr[n];
    pair<int,int>brr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].second;
    }
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
    }
    for(int i=0;i<n;i++){
        brr[i]={arr[i].first,arr[i].second};
    }
 
    sort(arr,arr+n,comp);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].first<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].second<<" ";
    // }
    // cout<<endl;
    int ans=p;
    int cnt=1;
    for(int i=0;i<n;i++){
        if(cnt+arr[i].second<=n){
            cnt+=arr[i].second;
            ans+=min(arr[i].first*arr[i].second,arr[i].second*p);
        
        }else{
            int remaining = n - cnt;
            ans += min((long long)arr[i].first * remaining, (long long)remaining * p);
            break;
        }
            // ans+=(n-cnt)*(p);
            // break;
        }
    
    ans=min(ans,n*p);
    cout<<ans<<endl;
   
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}