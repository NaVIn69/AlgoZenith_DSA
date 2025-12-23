#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100100];
void solve(){
    cin>>n;
    int crr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        crr[i]=arr[i];
    }
    // 1 1 1 2 3 3 5
    //2 3 3 5 1 1 1 
    sort(arr,arr+n);
    int cnt0=0;
    int f=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]==arr[0])cnt0++;
    }
    int brr[n];
    int i=0;
    for( ;i<n-cnt0;i++){
       brr[i+cnt0]=arr[i];
    }
    for(;i<n;i++){
        brr[i]=f;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(brr[i]>crr[i])ans++;
        cout<<brr[i]<<" ";
    }
    cout<<ans<<endl;

}
signed main(){
    solve();
}