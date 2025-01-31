#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int fib(int n){
    if(n<=1) return 1;
    return fib(n-1)+fib(n-2);
}


void solve(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;

}
signed main(){
    solve();
}