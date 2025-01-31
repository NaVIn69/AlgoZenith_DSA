#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
using lld=long double;
void solve(){
lli n;
cin>>n;
lli a[n],b[n];
vector<lld>c;
lli cnt=0;
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++){
    cin>>b[i];
}
int cnt1=0;
for(int i=0;i<n;i++){
    if(a[i]==0&&b[i]==0){
        cnt++;
    }else if(a[i]!=0&&b[i]!=0){
        lld k=-(b[i]/(lld)a[i]);
        c.push_back(k);
    }else if(b[i]==0&&a[i]!=0){
    cnt1++;///d==0
    }
    // cout<<c[i]<<" ";
}
sort(c.begin(),c.end());
int ans=INT_MIN;
int cnt2=1;
for(int i=0;i<c.size();i++){
    if(i==c.size()-1){
        continue;
    }else{
        if(c[i]==c[i+1]){
            cnt2++;
        }else{
            ans=max(cnt2,ans);
            cnt2=0;
        }
    }
}
ans=max(cnt2,ans);
cout<<max(ans,cnt1)+cnt<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}