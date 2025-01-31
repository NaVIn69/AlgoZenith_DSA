#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
lli sum_of_digits(lli n){
    lli sum=0;
    while(n!=0){
        sum=sum+(n%10);
        n=n/10;
    }
    return sum;
}
lli check(lli x,lli s){
    if((x-(sum_of_digits(x)))>=s){
        return 1;
    }else{
        return 0;
    }
}
void solve(){
lli n,k;
cin>>n>>k;
lli ans=n-1;
if(k==0){
    cout<<n<<endl;
    return;
}
if(n<10){
    cout<<"0"<<endl;
    return;
}
lli l=1;
lli h=n;
while(l<=h){
 lli mid=l+(h-l)/2;
 if(check(mid,k)==1){
   ans=mid;
   h=mid-1;
 }else{
    l=mid+1;
 }
}
cout<<n-ans+1<<endl;

}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}