#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,l,a;
pair<int,int> arr[100100];
void solve(){
 cin>>n>>l>>a;
 for(int i=0;i<n;i++){
    cin>>arr[i].first>>arr[i].second;
    
 }
 int run_sum=0;
 int prev_sum=0;
 int ans=0;
 for(int i=0;i<n;i++){
    ans+=(arr[i].first-prev_sum)/a;
    prev_sum=arr[i].first+arr[i].second;
 }
 if(prev_sum<l){
    ans+=(l-prev_sum)/a;
 }
 cout<<ans<<endl;

}
signed main(){
    solve();
}