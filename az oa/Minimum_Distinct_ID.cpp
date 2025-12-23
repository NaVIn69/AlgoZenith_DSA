#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
int arr[100100];
bool comp( pair<int,int>&p1, pair<int,int>&p2){
    return p1.second<p2.second;
}
void solve(){
   cin>>n>>m;
   map<int,int>mpp;
   for(int i=0;i<n;i++){
    cin>>arr[i];
    mpp[arr[i]]++;
   }
    vector<pair<int,int>>v(mpp.begin(),mpp.end());
    sort(v.begin(),v.end(),comp);
    int cnt=0;
    for(auto v1:v){
        if(m>=v1.second){
            m-=v1.second;
            cnt++;
        }else{
            break;
        }
    }
    cout<<v.size()-cnt<<endl;
   

}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}