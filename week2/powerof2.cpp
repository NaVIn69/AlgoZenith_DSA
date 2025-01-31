#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int pow_2[32];
void pow1(){
    pow_2[0]=2;
    for(int i=1;i<=31;i++){
     pow_2[i]=2*pow_2[i-1];
    }
}
void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
   /// pow1();
   
    int cnt=0;
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        int value_just_greater=*upper_bound(pow_2,pow_2+32,a[i]);
       
        int remaining=value_just_greater-a[i];
       // cout<<remaining<<" ";
        if(mpp.find(remaining)!=mpp.end()){
            cnt+=mpp[remaining];
        }
        mpp[a[i]]++;
    }
    cout<<cnt<<endl;

}
signed main(){
    ios_base :: sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
     pow1();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}