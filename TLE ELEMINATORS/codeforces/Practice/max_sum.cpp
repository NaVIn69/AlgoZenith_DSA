#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[200200];
void solve(){
    cin>>n>>k;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr+1,arr+n+1);
    int prefix[n+1]={0};
    
    for(int i=1;i<=n;i++){
       prefix[i]=arr[i];
       prefix[i]+=prefix[i-1];
    }
    // here we go through each possible combination of deleting min and max element
    int ans=0;
    for(int i=0;i<=k;i++){
        int min_ele=2*i;
        int max_ele=n-k+i;
        
        int rem=prefix[max_ele]-prefix[min_ele];
        ans=max(ans,rem);
        
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