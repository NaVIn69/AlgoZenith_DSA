#include<bits/stdc++.h>
using namespace std;
int n;
int a[100100];
void solve(){
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
int tot=0;
for(int mask=0;mask<(1<<n);mask++){
    int sum=0;
    for(int pos=0;pos<n;pos++){
        if((mask>>pos)&1){
            sum^=a[pos];
        }
    }
    tot+=sum;
    cout<<mask<<" "<<sum<<endl;
}
cout<<tot<<endl;
}
int main(){
    solve();
}