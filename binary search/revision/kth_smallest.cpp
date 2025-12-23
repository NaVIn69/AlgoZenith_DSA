#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m,k;
int arr[100100];
int brr[100100];
// here we always arr as the smallest size array

bool check(int mid){
    // here we have coun the if number of element(arr[i]+brr[j]) less than equal to x is greater thank return true;
    int cnt=0;
    // for evry arr[i], here we are counting the how many elment in brr array do that 
    for(int i=0;i<n;i++){
        if(arr[i]>mid) break;
        int rem=mid-arr[i];
        int idx=upper_bound(brr,brr+m,rem)-brr;
        cnt+=idx;
    
    }
    return cnt>=k;
}
void solve(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m;i++){
        cin>>brr[i];
    }
    if(n>m){
        swap(n,m);
        swap(arr,brr);
    }
    // here my search space is number of both array
    // the number of element in c(c[i]=arr[i]+brr[i])<=x should be greater than k

    sort(arr,arr+n);
    sort(brr,brr+m);
    int l=arr[0]+brr[0];
    int h=arr[n-1]+brr[m-1];
    int ans=l;
    while(l<=h){
        int mid=l+(h-l)/2;
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