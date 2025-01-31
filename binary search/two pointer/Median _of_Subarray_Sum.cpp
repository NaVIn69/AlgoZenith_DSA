#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];
int pre[100100];
bool check(int mid){
    // here we have to count the for every element
    // means how many subarray we can form from every element
    int cnt=0;
    for(int i=0;i<n;i++){
        int idx=upper_bound(pre+i,pre+n,mid)-pre;
        int num_ele=(idx-i);
        cnt+=num_ele;
        if(cnt>=k) return 1;
    } 
    return cnt>=k;
    
}
void solve(){
    int n;
    cin>>n;
    int mini=1e9;
    int sum=0;
int l=(n*(n+1));
k=(l+1)/2;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mini=min(mini,arr[i]);
        sum+=arr[i];
        pre[i]=arr[i];
        if(i){
            pre[i]+=pre[i-1];
        }
    }
    int l=mini;
    int h=sum;
    int ans=l;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    //here we have to find the correct value which can be formed from the subarray sum
    // int correct_val=0;
    // for(int i=0;i<n;i++){
    //     int index=lower_bound(pre+i,pre+n,)
    // }
    
    cout<<ans<<endl;
    

}
signed main(){
    ios_base::sync_with_studio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}