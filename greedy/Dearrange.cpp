#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define F first
#define S second
// bool cmp(pair<int,int>&p1,pair<int,int>p2){
//         p1.S<p2.S;
// }


  bool cmp( pair<int, int>& a,  pair<int, int>& b)  {
    return a.second < b.second;
  } 

int max(int a,int b){
    if(a>b) return a;
    else return b;
}
void solve(){
    int n;
    cin>>n;
    int arr[n];
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
       mpp[arr[i]]++;

    }
    vector<pair<int,int>>v(mpp.begin(),mpp.end());
    // sort(mpp.begin(),mpp.end(),myComparator());
    sort(v.begin(),v.end(),cmp);
    int max_freq=0;
    for(auto x:v){
        cout<<x.first<<" ";
        int val=x.second;
        max_freq=max(max_freq,val);
    }
    // max_dearrangement
    int fre=2*max_freq-n;
    int min_collision=max(fre,0);
    cout<<n-min_collision<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
}