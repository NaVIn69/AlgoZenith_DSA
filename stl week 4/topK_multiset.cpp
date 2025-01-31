#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int k;
struct bag{
   int sumK=0;
   multiset<int>high,low;
   void isbalanced(){
    
     if(high.size()<k){
        if(low.empty()) return;
        int y=*low.rbegin();
        low.erase(low.find(y));
        high.insert(y);
        sumK+=y;
     }
     if(high.size()>k){
        int x=*high.begin();
        high.erase(high.find(x));
        sumK-=x;
        low.insert(x);
     }

    }

   
   void insert(int x){
   high.insert(x);
   sumK+=x;
   isbalanced();

   }
   void remove(int x){
    
    if(low.find(x)!=low.end()){
        low.erase(low.find(x));
    }else if(high.find(x)!=high.end()){
        high.erase(high.find(x));
    }
    isbalanced();


   }
   int topK(){
    return sumK;
   }


};
signed main(){
    cin>>k;
    bag b1;
    b1.insert(9);
    b1.insert(7);
    b1.insert(10);
}