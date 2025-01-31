#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    do{
        for(int i=0;i<n;i++){
            if(i!=n-1){
            cout<<a[i]<<" ";
            }else{
                cout<<a[i]<<endl;
            }
        }
    }while(next_permutation(a,a+n));

}
signed main(){
    int t=1;

    while(t--){
        solve();
    }
}