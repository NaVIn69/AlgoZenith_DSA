#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int gcd(int a,int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int left_sum=sum-arr[n-1];
    int right_sum=arr[n-1];
  
    int j=n-1;
    int ans=1;
    while(j>0){
        j--;
        int g=gcd(left_sum,right_sum);
        ans=max(ans,g);
        right_sum+=arr[j];
        left_sum-=arr[j];
        // cout<<left_sum<<" "<<right_sum<<endl;  
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