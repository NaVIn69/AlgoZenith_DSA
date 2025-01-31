#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
void solve(){
lli n,k;
cin>>n>>k;
lli a[n];
for(lli i=0;i<n;i++){
    cin>>a[i];
}
// take two pointer
lli head=-1,tail=0;
 // datastructure which is used to maintain the window proprety
 map<int,int>mpp;
lli dist_ele=0;

// ans to store
lli ans=0;
while(tail<n){
    // eat as can you can eat
    while(head+1<n && (mpp[a[head+1]]==0 || dist_ele<k)){
        if(mpp[a[head+1]]==0) dist_ele++;
        mpp[a[head+1]]++;
        head++;
    }
    lli len=head-tail+1;
    ans+=len;
    // remove 
    if(tail<=head){
        mpp[a[tail]]--;
        if(mpp[a[tail]]==0) dist_ele--;
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