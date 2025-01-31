#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
void solve(){
lli n,sum;
cin>>n>>sum;
lli a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
lli head=-1,tail=0;
// datastructur to maintain the window proprety
lli sum_check=sum;
lli cnt=0;

// ans to store
lli ans=0;
while(tail<n){
    // eat as many as possible 
    while(head+1<n && sum_check>=a[head+1]){
        sum_check-=a[head+1];
        head++;
    }
    int len=head-tail+1;
    ans+=len;
    // remove the element
    if(tail<=head){
        sum_check+=a[tail];
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