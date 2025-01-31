#include<bits/stdc++.h>
using namespace std;
int n;
int a[100100];
void solve(){
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int mask=0;mask<(1<<n);mask++){

    for(int pos=0;pos<n;pos++){
        if((mask>>pos)&1){
            cout<<a[pos]<<" ";
        }
    }
    cout<<endl;
}
}
int main(){
    solve();
}