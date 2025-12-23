#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    int arr[n+1]={0};
   map<int,int>mpp; .// 
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[x]++;
    }
    for(int i=0;i<=n;i++){
        mt.insert(i);
    }
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            mt.erase(i);
        }
    }
    int mex=*mt.begin();
    sort(arr,arr+n);

    // on the basis of counting we sort 
    int maxi=0; // first increase then decrease 
    for(int k=0;k<=n;k++){
        if(k==0){
            cout<<mex<<" ";
        }else{
            int idx=upper_bound(arr,arr+n,k)-arr;
            if(arr[idx]==0){
              
            }
        }
    }

}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}