#include<bits/stdc++.h>
using namespace std;
void solve(){
 int n,m;
 cin>>n>>m;
 int arr[n],brr[m];
 map<int,int>mpp,mpp2;

 for(int i=0;i<n;i++){
    cin>>arr[i];
    mpp[arr[i]]++;
    mpp2[arr[i]]++;

 }
 for(int i=0;i<m;i++){
    cin>>brr[i];
    mpp[brr[i]]++;
    if(mpp2.find(brr[i])==mpp2.end()){
           mpp2.erase(mpp2[brr[i]]);
    }
 }
 for(int i=0;i<n;i++){
    if(mpp2.find(arr[i])==mpp2.end()){
        
    }
 }
 for(auto v:mpp){
    cout<<v.first<<" ";
 }
 cout<<endl;
 for(auto v:mpp2){
    cout<<v.first<<" ";
 }
 cout<<endl;

}
int main(){
    solve();
}