#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n;
    cin>>n;
    int arr[n]={0};
    int i=1;
    int j=n-2;
    int k=n;
    arr[0]=k;
    k--;
    arr[n-1]=k;
    k--;
    while(i<=j){
        if(arr[i-1]>arr[j-1]){
            arr[j]=k;
            k--;
            if(k==0) break;
            j--;
            arr[i]=k;
            k--;
            if(k==0) break;
            i++;
        }else{
            arr[i]=k;
            k--;
                        if(k==0) break;
            i++;
            arr[j]=k;
            k--;
                        if(k==0) break;
            j--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   
    

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}