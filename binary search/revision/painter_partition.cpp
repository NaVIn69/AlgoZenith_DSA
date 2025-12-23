// here we have given wall which i have to paint and now , we have given time to paint the wall section wise,
// we have to find the maximum minimum time to paint the wall
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];
bool check(int mid){
    int tot=mid;
    int cnt_p=1;
    for(int i=0;i<n;i++){
        if(arr[i]<=tot){
            tot-=arr[i];
        }else{
            tot=mid;
            cnt_p++;
            if(cnt_p>k) return false;
            if(arr[i]<=mid){
                tot-=arr[i];
            }else{
                return false;
            }

        }
    }
    return cnt_p<=k;
}

void solve(){
cin>>n>>k;
int l=1e9;
int h=0;
for(int i=0;i<n;i++){
    cin>>arr[i];
    l=min(l,arr[i]);
    h+=arr[i];
}
// here my search sapce is the time , here we have to search on time such that can we complete the painter painting the wall with give painter
int ans=l;
while(l<=h){
    int mid=l+(h-l)/2;
    // can we paint wall in at max mid time with k painter
    if(check(mid)){
       ans=mid;
       h=mid-1;
    } else{
        l=mid+1;
    }
}
cout<<ans<<endl;

}
signed main(){
    solve();
}