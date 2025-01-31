#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
   int q;
   cin>>q;
   map<string ,int>mpp;
   while(q--){
      string op,name;
   
      cin>>op>>name;
      if(op=="add"){
         int marks;
         cin>>marks;
         mpp[name]=marks;
      }else if(op=="erase"){
         mpp.erase(name);
      }else{
         if(mpp.find(name)!=mpp.end()){
            cout<<mpp[name]<<endl;
         }else{
            cout<<"0"<<endl;
         }
      }

   }

}
signed main(){
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t=1;
     cin>>t;
     while(t--){
     
        solve();
     }
    
}