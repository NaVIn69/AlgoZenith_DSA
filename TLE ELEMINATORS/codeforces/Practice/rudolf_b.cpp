#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(arr[1]>=2*arr[0]&&arr[2]>=arr[0]){
        arr[1]-=2*arr[0];

        arr[2]-=arr[0];
        arr[0]=0;
        if(arr[2]<0){
            cout<<"NO"<<endl;
            return ;
        }
    }else{
        cout<<"NO"<<endl;
        return ;
    }

    if(arr[n-2]>=2*arr[n-1]&&arr[n-3]>=arr[n-1]){
        arr[n-2]-=2*arr[n-1];

        arr[n-3]-=arr[n-1];
        arr[n-1]=0;
        if(arr[n-3]<0){
            cout<<"NO"<<endl;
            return ;
        }
    }else{
        cout<<"NO"<<endl;
        return ;
    }


     int cnt=0;
    for(int i=2;i<n-2;i++){
        if(arr[i]>=2*arr[i-1]&&arr[i+1]>=arr[i-1]){
            arr[i]-=2*arr[i-1];
            arr[i+1]-=arr[i-1];
            arr[i-1]=0;
        }else{
            cout<<"NO"<<endl;
            return ;
        }
    }

    for(int i=0;i<n;i++){
         if(arr[i]!=0){
            cout<<"NO"<<endl;
            return ;
         }  
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