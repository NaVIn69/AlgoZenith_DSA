#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    if(n%2){
        cout<<"1"<<endl;
    }else{
        int cnt=2;
        int temp=3;
        while(n%temp==0){
            temp++;
            cnt++;
        }
        cout<<cnt<<endl;


    }
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}