#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

bool comp(pair<int,int>&a,pair<int,int>&b){
    if(a.second<b.second){
        return true;
    }
    return false;
}

vector<pair<int,int>>prime_factorisation(int n){
    vector<pair<int,int>>ans;
    for(int i=2;i*i<=n;i++){
      if(n%i==0){
        int cnt=0;
        while(n%i==0){
          cnt++;
          n/=i;
        }
        ans.push_back({i,cnt});
      }
    }
    if(n>1){
      ans.push_back({n,1});
    }
    return ans;
  
  
  }
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>>arr=prime_factorisation(n);
    sort(arr.begin(),arr.end(),comp);
    int prod=1;
    for(auto x:arr){
        prod=prod*(x.first);
        // cout<<x.first<<" "<<x.second<<endl;
    }
    int curr_prod=1;
    int curr_tot=0;
    int ans=0;
    for(int i=0;i<arr.size();i++){
         ans+=((arr[i].second-curr_tot)*(prod/curr_prod));
         curr_prod=curr_prod*arr[i].first;
         curr_tot=arr[i].second;
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