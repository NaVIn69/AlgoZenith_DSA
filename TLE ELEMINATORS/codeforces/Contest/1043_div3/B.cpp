#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int Pow[20];
void pow10(){
    Pow[0]=1;
    for(int i=1;i<=18;i++){
        Pow[i]=Pow[i-1]*10LL;
    }

}
void solve(){
   int n;
   cin>>n;
   //n=x(1+10^k);
   int k=18;
   set<int>st;
   for(int i=1;i<=k;i++){
        int denom=1+Pow[i];
        if(denom>n)break;
        if(n%denom==0){
            int x=n/denom;
            if(x>0){
               st.insert(x);
            }
        }
   }
   if(st.empty()){
    cout<<"0"<<endl;
    return;
   }
   cout<<st.size()<<endl;
   for(auto x:st){
       cout<<x<<" ";
   }
   cout<<endl;




}
signed main(){
    int t=1;
    cin>>t;
    pow10();
    while(t--){
        solve();
    }
}