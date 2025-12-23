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
    vector<int>arr(n),brr(n);
    int mini=1e9+7;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        brr[i]=arr[i];
        mini=min(mini,arr[i]);
    }
    sort(brr.begin(),brr.end());// my final array 
    for(int i=0;i<n;i++){
        int o_ele=arr[i];
        int final_ele=brr[i];
        if(final_ele==o_ele)continue;
        if(final_ele%mini==0&&o_ele%mini==0){
            continue;
        }else{
            cout<<"NO"<<endl;
             return;
        }
        // int g=gcd(o_ele,final_ele);
        // if(g!=mini){
        //     cout<<"NO"<<endl;
        //     return;
        // }
    }
    cout<<"YES"<<endl;
    

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}