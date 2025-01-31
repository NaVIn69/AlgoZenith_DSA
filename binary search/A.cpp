#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
int check(int*a,int mid,int k,int n){
    int needed_points=0;
    for(int i=1;i<n;i++){
        needed_points=needed_points+(((a[i]-a[i-1])+mid-1)/mid)-1;
    }
    if(needed_points<=k){
        return 1;
    }else{
        return 0;
    }
}
void solve(){
int n,k;
cin>>n>>k;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
int l=0;
int h=0;
for(int i=1;i<n;i++){
    h=max(h,(a[i]-a[i-1]));
}

int ans=h;
if(k==0||h==1){
    cout<<ans<<endl;
}
while(l<=h){
    int mid=l+(h-l)/2;
    if(check(a,mid,k,n)==1){
        ans=mid;
        h=mid-1;
    }else{
        l=mid+1;
    }
}
cout<<ans<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
    solve();        
    }
}