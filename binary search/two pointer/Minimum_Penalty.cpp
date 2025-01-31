#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int freq[1000005]={0};
void solve(){
int n,d;
cin>>n>>d;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
// take two pointers;
// first the 
// here we are using the permutation matching concept to find the distnict element
int ans=INT_MAX;
int dist=0;
for(int i=0;i<n;i++){
    
    if(i-d>=0){
        ans=min(ans,dist);
        // next element ko include krna hai
      //  if(freq[a[i]]==0) dist++;
        freq[a[i-d]]--;
        if(freq[a[i-d]]==0) dist--;
    }
     if(freq[a[i]]==0) dist++;
    freq[a[i]]++;
}
   
for(int i=n-d;i<n;i++){
    freq[a[i]]=0;
}
ans=min(ans,dist);
cout<<ans<<endl;



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