#include<bits/stdtr1c++.h>
using namespace std;
void solve(){
int n;
cin>>n;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if((max(abs((n/2)-i),abs((n/2)-j))+n/2)%2!=0){
            cout<<"*";
        }else{
            cout<<".";
        }
    }
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