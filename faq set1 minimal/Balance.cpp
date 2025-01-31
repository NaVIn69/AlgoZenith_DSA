#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,limit;
int arr[100100];
int maxi_limit=2*limit;
int mini_limit=2;
bool check(int mid){
    map<int,pair<int,int>>mpp;
    vector<pair<int,int>>v;
    //here map store the maximum number of sum (of two number kis number pe hai)
    int i=0;
    int j=n-1;
    int num_has_tobe_replaced=0;
    while(i<j){
        int sum=arr[i]+arr[j];
        mpp[sum].first=arr[i];
        mpp[sum].second++;
        
        i++;
        j--;
    }
    //here we count which have maximum pair sum counting
    int maxi=0;
    int tot=0;
    int maxi_sum=0;
    for(auto v:mpp){
        tot+=v.second.second;
       maxi=max(maxi,v.second.second);
       if(maxi==v.second.second){
         maxi_sum=v.first;
       }
    }
     int cnt=0;
     for(auto v:mpp){
        if(v.second.second!=maxi){
            int rem=maxi_sum-v.second.first;
            if(rem<=limit){
                cnt++;
            }else{
                cnt+=2;
            }
        }
     }
     return mid>=cnt;
}
void solve(){
    cin>>n>>limit;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // check given array is arthematic or not 
    // if given array is not arthematic then  we can replace any element in between 1 to limit (inclusive)
    //here we can do the binary search on minimum number of moves 
    // and we can 
    int l=0;
    int h=n;
    int ans=0;
    while(l<=h){
        int mid=(l+h)/2;
        if(check(mid)){
            ans=mid;
            h=mid-1;
        }else{
            l=mid+1;
        }

    }
    cout<<ans<<endl;

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
