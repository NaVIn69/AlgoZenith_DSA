#include<bits/stdc++.h>
using namespace std;
void print_row(int i,int n){
    for(int j=0;j<26;j++){
        if(i%5==(j%8)||i%5+(j%8)==8){
            cout<<char('A'+j);
        }else{
            cout<<' ';
        }
    }
}
void solve(){
int n;
cin>>n;
for(int i=0;i<n;i++){
    print_row(i,n);
    cout<<endl;
}
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}