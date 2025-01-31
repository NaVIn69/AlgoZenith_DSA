#include<bits/stdc++.h>
using namespace std;
void printrecurssive( unsigned int x){
    if(x>1){
        printrecurssive(x/2);

    }
    cout<<x%2;
}
void solve(){
unsigned int n;
cin>>n;
for(int i=31;i>=0;i--){
    if((1<<i)&n){
        cout<<"1";
    }else{
        cout<<"0";
    }
}
cout<<endl;


}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 
      int t;
   cin>>t;
   while(t--){
    solve();
   }
}