#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
using lld=long double;
void solve(){
lli n;
string m;
cin>>n>>m;
int index=m.find('.');
stringstream ss;
string beforedecimal=m.substr(0,index);
string afterdecimal=m.substr(index+1);
int num_afterdecimal=n+stoll(beforedecimal);
int num_beforedecimal=n+stoll(afterdecimal);
cout<<num_beforedecimal<<"."<<num_afterdecimal<<endl;
   
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}