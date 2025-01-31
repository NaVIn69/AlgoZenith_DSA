#include<bits/stdc++.h>
using namespace std;
void print_cell(int i,int j,int n){
    int decide=max(abs(i-n/2),abs(j-n/2));
    char ch1='*';
    char ch2='*';
    if(n%4==3){
        swap(ch1,ch2);
    }
    if((decide+n/2)%2==0){
        cout<<"*";
    }else{
        cout<<".";
    }
}
void print_row(int i,int n){
    for(int j=0;j<n;j++){
        print_cell(i,j,n);
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
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<min({0,0,0})<<endl;
    }
}