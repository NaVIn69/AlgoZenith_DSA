#include<bits/stdc++.h>
using namespace std;
 void solve(){
int n,k;
cin>>n>>k;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
// take two pointer
int head=-1,tail=0;
// datastructure is used to maintain the window proprety 
map<int,int>mpp;
int check=k;

// ans to store
int ans=0;
while(tail<n){
   // eat as many as you can eat
   while(head+1<n && (mpp[a[head+1]]==0||check!=0 || a[tail]!=-1)){
    if(mpp[a[head+1]]==0){}
    mpp[a[head+1]]++;
    a[head+1]=-1;
    check--;
   
   head++;
   }
   
   if(mpp.size()==k){
    mpp.erase();
    ans++;
   }
   // remove 
   if(tail<=head){
    tail++;
   }else{
    tail++;
    head=tail-1;
   }
}
cout<<ans<<endl;
 }
 int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
      }
 }