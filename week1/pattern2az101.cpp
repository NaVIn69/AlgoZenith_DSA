#include<bits/stdc++.h>
using namespace std;
void print_cell(int i,int j,int n,int m,int k,int p){

}
void print_row(int i,int n,int m,int k,int p){
    for(int j=0;j<m-1;j++){
        print_cell(i,j,n,m,k,p);
        cout<<endl;
    }
    for(int i=0;i<k;i++){
        cout<<"*";
    }

}
void solve(){
int n,m,p;
cin>>n>>m>>p;

int k=m*p+m+1;
for(int i=0;i<k;i++){
    cout<<"*";
}
cout<<endl;
for(int i=0;i<n;i++){
    print_row(i,n,m,k,p);
    cout<<endl;
}
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    cout<<min({0,0,0})<<endl;
}