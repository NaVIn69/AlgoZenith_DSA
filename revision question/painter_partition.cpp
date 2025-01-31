
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];
bool check(int mid){
    //here mid is time // means can 3 painter can complete their work in that time
    int lastleft=mid;
    int needed=1;
    for(int i=0;i<n;i++){

        if(lastleft>=arr[i]){
            lastleft-=arr[i];
        }else{
            needed++;
            lastleft=mid;
            lastleft-=arr[i];
        }
        if(needed>k) return 0;

    }
    return 1;
}
void solve(){
    cin>>n>>k;
    //search space 
    // 
    int min_time=0;
    int max_time=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        min_time=max(min_time,arr[i]);
        max_time+=arr[i];
    }
    int l=min_time;
    int h=max_time;
    int ans=max_time;
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
    solve();
}