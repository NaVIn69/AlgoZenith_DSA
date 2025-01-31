#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin>>n;
    long long sum=0;
    while(n!=0){
        cout<<n<<endl;
sum+=n%10;
    n=(long long)n/10;
    cout<<n<<endl;
    }
    cout<<n<<endl;
    cout<<sum<<endl;

}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}