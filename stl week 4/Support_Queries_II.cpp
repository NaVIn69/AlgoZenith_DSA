#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int k;
struct bag{
   int sumK=0;
   multiset<int>high,low;
  /* void isbalanced(){
    if(high.size()>k){
        int x=*high.begin();
        low.insert(x);
        high.erase(high.find(x));
        sumK-=x;
    }
    if(high.size()<k){
           if(low.size()!=0){
          int x=*low.rbegin();
          high.insert(x);
          sumK+=x;
          low.erase(low.find(x));
           }
    }

   }*/
   void insert(int x){
    high.insert(x);
    sumK+=x;
    if(high.size()>k){
        int p=*high.begin();
        high.erase(high.find(p));
        sumK-=p;
        low.insert(p);
    }
    
    
    // for maintain the top k element in high multiset
  //  isbalanced();

   }
   void remove(int x){
    
   if(low.find(x)!=low.end()){
    low.erase(low.find(x));
   }else if(high.find(x)!=high.end()){
    high.erase(high.find(x));
    sumK-=x;
    if(low.empty()) return;
    int a=*low.rbegin();
    low.erase(low.find(a));
    high.insert(a);
    sumK+=a;
   }


   }
   int topK(){
    return sumK;
   }


};
 void solve(){
    int q;
    cin>>q>>k;
    bag b1;
    while(q--){
        int n;
        cin>>n;
        if(n==1){
           int x;
           cin>>x;
           b1.insert(x);
        }else if(n==2){
            int x;
            cin>>x;
            b1.remove(x);
        }else{
            char ch;
            cin>>ch;
            int sumK=b1.topK();
            cout<<sumK<<endl;
        }
    }

 }
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
}