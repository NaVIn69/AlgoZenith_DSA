#include<bits/stdc++.h>
using namespace std;
int n;
int a[100100];
void prefix_sum(int*a,int*b,int n){
    for(int i=0;i<n;i++){
        if(i==0){
            b[i]=a[i];
        }else{
            b[i]=a[i]+b[i-1];
        }
    }
}
void solve(){
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b[n];
    prefix_sum(a,b,n);
    for(int i=0;i<n;i++){
      cout<<b[i]<<" ";
    }


}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}