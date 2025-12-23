#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100100];
void solve(){

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=(arr[i]*(i+1)*(n-i));
    }
    cout<<sum<<endl;


}
signed main(){
    solve();
}