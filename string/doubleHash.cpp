// when two string length is larger than 1000 then , we use double hash to avoid the collision

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct hasher{
   int sz,_p, _mod;
   vector<int>fhash,revhash,pk;
   void init(string s,int p,int mod){
    sz=s.size();
    _p=p;
    _mod=mod;
   
    fhash.resize(sz);
    revhash.resize(sz);
    pk.resize(sz);
    // forward hashing 
    fhash[0]=s[0]-'a'+1;
    pk[0]=1;
    for(int i=1;i<s.size();i++){
        fhash[i]=fhash[i-1]*p+(s[i]-'a'+1)%mod;
        pk[i]=(pk[i-1]*p)%mod;
    }
    /// reverse hashing 
    // 
    revhash[sz-1]=s[sz-1]-'a'+1;
    for(int i=sz-2;i>=0;i--){
       revhash[i]=(revhash[i-1]*p+(s[i]-'a'+1))%mod;
    }
     
   }
   int getfhash(int l,int r){
    if(l==0) return fhash[r];
    return ((fhash[r]-fhash[l-1]*pk[r-l+1])%_mod+_mod)%_mod;
   }

   int getrevhash(int l,int  r){
       if(r==sz-1) return revhash[l];
       return ((revhash[l]-revhash[r+1]*pk[r-l+1])%_mod+_mod)%_mod;
   }

};
struct double_hash{
     hasher a,b;
    void init(string s){
        a.init(s,31,1e9+7);
        b.init(s,39,1e9+7);
    }
    pair<int,int> getfhash(int l,int r){
        return {a.getfhash(l,r),b.getfhash(l,r)};
       
    }
    pair<int,int>getrevhash(int l,int r){
        return {a.getrevhash(l,r),b.getrevhash(l,r)};
    }
};
void solve(){
    
  string s;
  cin>>s;
  double_hash sh;
  sh.init(s);
  int l=s.size()-1;
  cout<<sh.getfhash(0,l).first<<" "<<sh.getfhash(0,l).second<<endl;
  cout<<sh.getrevhash(0,l).first<<" "<<sh.getrevhash(0,l).second<<endl;
}
signed main(){
    solve();
}