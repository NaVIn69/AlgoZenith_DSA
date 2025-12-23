#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    int arr[n],brr[n];
    int tot1=0;
    int tot0=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==1){
            tot1++;
        }else{
            tot0++;
        }
    }
    for(int i=0;i<n;i++){
        cin>>brr[i];
        if(brr[i]==1){
            tot1++;
        }else{
            tot0++;
        }
    }
    if(tot0==0 || tot1==0){
        cout<<max(tot0,tot1)<<endl;
        return;
    }
    if(tot0==tot1){
        cout<<0<<endl;
        return ;
    }
    int i=0,j=n-1;
    while(j>=0||i<n){
         
    }
    

}
signed main(){
    solve();
}