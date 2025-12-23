/*
You have given a graph G with n nodes and m edges. Each edge has an integer weight associated with. The weight of an edge may negative, positive or zero. If the graph contains a cycle with total weight > 0, print -1. Otherwise, find the weight of the highest weighted path from node 1 to n
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    int diff[n-1]={0};
    int total=0;
    int p=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i){
            diff[p]=abs(arr[i]-arr[i-1]);
            total+=diff[p];
            p++;
            // total+=diff[];
        }
    }
    if(n==1){
        if(arr[0]<k){
            cout<<k<<endl;
            return;
        }else{
            cout<<arr[0]<<endl;
            return;
        }
    }
    ///finding two concesutive sum lesser
    

    int index1=0;
    int index2=0;
    int sum=0;
    int mini=INT_MAX;
    for(int i=0;i<n-2;i++){
        sum=diff[i]+diff[i+1];
        mini=min(mini,sum);
        if(mini==sum){
            index1=i;
            index2=i+1;
        }
    }
    if(index2==0){
        if(arr[index2+1]>k/2){
            arr[index2]=1;
        }else{
            arr[index2]=k;
        }
    }
    if(index2==n-1){
        if(arr[index2-1]>k/2){
            arr[index2]=1;
        }else{
            arr[index2]=k;
        }
    }
    int val=0;
     int maxi=0;
    for(int i=1;i<=k;i++){
        int sum1=0;
        if(index2-1>=0&&index2+1<n){
         sum1=abs(arr[index2-1]+arr[index2+1]-2*i);
        }
       // cout<<sum1<<" ";
        maxi=max(maxi,sum1);
    }
     
    cout<<total-diff[index1]-diff[index2]+maxi<<endl;


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