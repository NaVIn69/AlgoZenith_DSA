#include<bits/stdc++.h>
using namespace std;
void printrow(int n){
    for(int j=0;j<n;j++){
        cout<<"*";
    }
     cout<<endl;
}
void print_e(int n){
    for(int j=0;j<n;j++){
        if(j%2==0){
            cout<<"*";
        }else{
            cout<<".";
        }
    }
    cout<<endl;
}
void print_o(int n){
    for(int i=0;i<n;i++){
        if(i==0||i==n-1){
            cout<<"*";
        }else{
            cout<<".";
        }
    }
    cout<<endl;
}
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        if(i==0||i==n-1){
            printrow(n);
        }else if(i%2==0){
            print_e(n);
        }else{
            print_o(n);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}