// there are n person which has (l,r) entry time and exit time 
// we have to find the numebr of person which is greater than k

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>event;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        event.push_back({l,1});
        event.push_back({r,-1});
    }
    // traversing that time
    sort(event.begin(),event.end());
    //here cnt is the data structure  which is used to count the person in that interval
    int cnt=0;
    int ans=0;
    for(int i=0;i<n;i++){
          cnt+=event[i].second;
          if(i+1<n && cnt>=k){
            ans+=event[i+1].first-event[i].first;
          }
    }
    cout<<ans<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}