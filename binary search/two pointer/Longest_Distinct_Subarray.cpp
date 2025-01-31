#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
void solve(){
lli n;
cin>>n;
lli a[n];
for(lli i=0;i<n;i++){
    cin>>a[i];
}
// take two pointer
lli head=-1,tail=0;
// data structure is used to maintain the window proprety
map<int,int>mpp;

// ans to store
lli ans=0;
while(tail<n){
    // eat as mmany element you can
    while(head+1<n && mpp[a[head+1]]==0){
        mpp[a[head+1]]++;
        head++;
    }
    // store the current lent 
    lli len =head-tail+1;
    // update ans
    ans=max(ans,len);

    // remove the element
    if(tail<=head){
        mpp[a[tail]]--;
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