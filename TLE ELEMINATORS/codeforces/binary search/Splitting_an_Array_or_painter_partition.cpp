#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,k;
int arr[100100];
bool fuck(int mid){
    // can we complete my task in the mid time with k painter
    int cnt=1;
    int val=mid;
    for(int i=0;i<n;i++){
        if(arr[i]<=val){
            val-=arr[i];
        }else{
           cnt++;
           val=mid;
           if(arr[i]>val) return false;
           val-=arr[i];
           if(cnt>k)return false; 
        }
        if(cnt>k)return false;
    }

    return cnt<=k;

} 

void solve(){
    cin>>n>>k;
    int sum=0;;
    int maxi=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];// here we have one painter 
        maxi=max(arr[i],maxi); // here we have n painter then 
        }
        
        int l=1;
        int h=sum;
        int ans=l;
        while(l<=h){
            int mid=(l+h)/2;
            if(fuck(mid)){
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