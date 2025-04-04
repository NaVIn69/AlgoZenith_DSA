#include<bits/stdc++.h>
using namespace std;
int balancedSUm(vector<int>&arr){
    int n=arr.size();
    vector<int>pre,suf;
    pre.assign(n,0);
    suf.assign(n,0);
    for(int i=0;i<n;i++){
        pre[i]=arr[i];
        if(i){
            pre[i]+=pre[i-1];
        }
         // cout<<pre[i]<<" ";
    }
    cout<<endl;
     suf[n-1]=arr[n-1];
    //  cout<<suf[n-1]<<" ";
    for(int i=n-2;i>=0;i--){
       
       suf[i]=arr[i];
            suf[i]+=suf[i+1];
        // cout<<suf[i]<<" ";
      
    }
    cout<<endl;
    int mini=INT_MAX;
    int index=0;
    for(int i=1;i<n;i++){
        int pre_val=pre[i-1];
        int suf_val=suf[i+1];
        if(pre_val==suf_val){
           mini=min(mini,arr[i]);
           if(mini==arr[i]){
            index=i;
           }
        }
    }
    return index;
}
int main(){
   int n;
   cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++){
    cin>>v[i];
}
cout<<balancedSUm(v)<<endl;
}