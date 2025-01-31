#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];
map<int,int>mpp;
bool check(int mid){
    //each basket has atleast k balls
    //total ball we needed is k*mid
    int needed_ball=k*mid;

    int tot=0;
    for(auto v:mpp){
        tot+=min(v.second,mid);
    }
    return tot>=needed_ball;
     
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mpp[arr[i]]++;
    }
    int l=0;
    int h=n/k;
    int ans=0;
    while(l<=h){
        int mid=(l+h)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            h=mid-1;
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