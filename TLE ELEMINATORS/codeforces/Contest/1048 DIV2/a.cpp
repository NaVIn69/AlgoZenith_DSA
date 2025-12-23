#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
   int k,x;
   cin>>k>>x;
   int f_a=(1LL<<k); // -> x
   int f_b=(1LL<<k);  // tot-x
   int tot=(1LL<<(k+1));
   int i_a=x;
   int i_b=tot-x;
   // inverse  op1-> b>a , op2-> a>b
   if(f_a==i_a&&f_b==i_b){
    cout<<0<<endl;
    cout<<endl;
    return ;
   }
   vector<int>op;
   int ans=0;
   while(i_a!=f_a || i_b!=f_b){
       if(i_b>i_a){
         // 
         op.push_back(1);
         int a=i_a,b=i_b;
        i_a=(a<<1);
         i_b-=a;
       }else{
         op.push_back(2);
         int a=i_a,b=i_b;
          i_b=(b<<1);
          i_a-=b;
       }
   }
   reverse(op.begin(),op.end());
   cout<<op.size()<<endl;
   for(int i=0;i<op.size();i++){
       cout<<op[i]<<" ";
   }
   cout<<endl;



}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}