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
    int l=k,r=k;
    int cnt=k;
    while(l<n&&r<n){
        if(arr[l-1]==arr[r]&&cnt<k){
            arr[l]=arr[r];
            l++;
            r++;
            cnt++;
        }else if(arr[l-1]==arr[r]&&cnt>=k){
            r++;
        }else{
            arr[l]=arr[r];
            cnt=1;
            l++;
            r++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


}
signed main(){
   solve();
}