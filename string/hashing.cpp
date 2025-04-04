#include<bits/stdc++.h>
using  namespace std;
#define int long long
#define endl "\n"
// we have to base(p) always greater than 26 
// bcz p>26 then each char has their unique value
int quickhash(string s,int p,int mod){
    int ans=s[0]-'a'+1;
    // here a=1 b=2 c=3 ......... z=26
    for(int i=1;s[i]!='\0';i++){
        ans=(ans*p+s[i]-'a'+1)%mod;
    }
    return ans;
}

struct hasher{
    int sz; int mod,p;
    vector<int>fHash;
    vector<int>powK,rev;
    // here fHash store the forward hash os string
    // here powK store the power of p
    void init(string s,int _p,int _mod){
        mod=_mod; p=_p;
        sz=s.length();
        fHash.resize(sz);
        powK.resize(sz);
       /// forwardhashing
       fHash[0]=s[0]-'a'+1;
       powK[0]=1;
       for(int i=1;i<sz;i++){
        fHash[i]=(fHash[i-1]*p+s[i]-'a'+1)%mod;
        powK[i]=(powK[i-1]*p)%mod;
       }

       // rev hashing
    
        rev.resize(sz);
        rev[sz-1] = s[sz-1]-'a'+1;
        for(int i=sz-2;i>=0;i--){
             rev[i]=(rev[i+1]*p+s[i]-'a'+1)%mod;
        }
    }

    // geting the forward hash
    int getfHash(int l,int r){
        if(l==0) return fHash[r];
        else{
            return (fHash[r]-(fHash[l-1]*powK[r-l+1])%mod+mod)%mod;
        }
    }
      int getrevhash(int l,int r){
        if(r==sz-1) return rev[l];
        else{
              return (rev[l]-(rev[r+1]*powK[r-l+1])%mod+mod)%mod;
        }
        // int ans = (rev[l] - 1LL *rev[r+1]*powK[(r-l+1)])%mod;
        // return (ans+mod)%mod;
    }


};

struct double_hash{
    hasher a,b;
    void init(string s){
        a.init(s,37,1000000021);
        b.init(s,39,1000000009);
    }
    pair<int,int> gethash(int l,int r){
        return {a.getfHash(l,r),b.getfHash(l,r)};
    }
    pair<int,int> getrevhash(int l,int r){
        return {a.getrevhash(l,r),b.getrevhash(l,r)};
    }
    bool is_palin(int l,int r){
        return gethash(l,r) == getrevhash(l,r);
    }
};

void solve(){

   double_hash shash1;
//    shash1.init(s,31,999999937);
//    shash2.init(s,29,1000000021);
   int n;
   map<pair<int,int>,string>mpp;
   for(int i=0;i<n;i++){
     string str;
     cin>>str;
        shash1.init(str);

     pair<int,int>p=shash1.gethash(0,str.size());
     mpp[p]=str;
   }
    



 

}
signed main(){
    int t=1;
  //  cin>>t;
    while(t--){
    solve();
    }
}