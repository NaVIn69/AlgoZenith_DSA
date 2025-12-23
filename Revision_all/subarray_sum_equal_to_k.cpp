#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    int ans=0;
    map<int,int>mpp;
    // here we have to find out the total sibarrray sum equal to k
    for(int i=0;i<n;i++){
        sum+=arr[i];
        int rem=sum-k;
        if(mpp.find(rem)!==mpp.end()){
            ans+=mpp[rem];
        }
        mpp[sum]++;

    }
    cout<<ans<<endl;

}
signed main(){
    solve();
}