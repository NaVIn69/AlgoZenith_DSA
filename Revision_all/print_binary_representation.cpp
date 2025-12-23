#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void bit_representation(int x){
    for(int i=31;i>=0;i--){
        if((x>>i)&1){ // checking the ith bit is set or not
            cout<<"1";
        }else{
            cout<<"0";
        }
    }
    cout<<endl;
}
void solve(){
    int n;
    cin>>n;
    bit_representation(n);

}
signed main(){
    solve();
}