#include<bits/stdc++.h>
using namespace std;
void solve(){
int n,k;
cin>>n>>k;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
// two pointer
int head=-1,tail=0;

// data structure 
map<int,int>mpp;
int dist_cnt=0;

// ans to store
int ans=0;

while(tail<n){
    // eat as many element as possible
    while(head+1<n && (mpp[a[head+1]]!=0 || dist_cnt<k)){
        if(mpp[a[head+1]]==0) dist_cnt++;
        mpp[a[head+1]]++;
        head++;
    }
    // save the current best length 
    int len=head-tail+1;
    // update the ans
    ans=max(ans,len);

  // remove the element from starting ans add the element from end
     if(tail<=head){
       if(mpp[a[tail]]==1) dist_cnt--;
       tail++;
     }else{ // when empty
      tail++;
      head=tail-1;
     }
}
cout<<ans<<endl;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}