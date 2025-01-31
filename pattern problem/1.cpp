#include<bits/stdc++.h>
using namespace std;
void print(int n,int m){
    int k=m+1+m*2;
for(int i=0;i<3;i++){
   for(int j=0;j<m;j++){
       if(i!=2){
    cout<<"*..";
       }else{
     cout<<"***";
       }
   }
    cout<<"*"<<endl;
}
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
cout<<"***";
    }
    cout<<"*"<<endl;
    for(int i=0;i<n;i++){
     print(n,m);
    }
    
}
int main(){
int t=1;
    cin>>t;
    while(t--){
   solve();
    }
}