#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we have to give the p as the prime number base which is greater than 26 and mod we used when the number goes outside of int range
// base is 31 ,37

struct hasher{
    int sz,mod,p;
    vector<int>fhash,revhash;
    vector<int>pk;

    void init(string s,int _p,int _mod){
        mod=_mod;
        p=_p;
        sz=s.size();
        fhash.resize(sz);
        fhash[0]=(s[0]-'a'+1);
     
        pk.resize(sz);
        revhash.resize(sz+1);
        revhash[sz]=0;
        pk[0]=1;
        for(int i=1;i<s.size();i++){
            fhash[i]=(fhash[i-1]*p+(s[i]-'a'+1))%mod;
            pk[i]=(pk[i-1]*p)%mod;
        }
        for(int i=sz-1;i>=0;i--){
            revhash[i]=(revhash[i+1]*p+(s[i]-'a'+1))%mod;
        }
    }

        int getHash(int l,int r){
            if(l==0) return fhash[r];
            return ((fhash[r]-fhash[l-1]*pk[r-l+1])%mod+mod)%mod;
        }
       int getrevHash(int l,int r){
        if(r==sz-1) return revhash[l];
        return ((revhash[l]-revhash[r+1]*pk[r-l+1])%mod+mod)%mod;
       }
    

// finding the hash of substring

};
int quickHash(string s,int p,int mod){
     int ans=s[0]-'a'+1;
     for(int i=1;i<s.size();i++){
        ans=ans*p+(s[i]-'a'+1);
     }
     return ans;
}
void solve(){
  string s;
  cin>>s;
  hasher sh;
  sh.init(s,31,1e9+7);
  cout<<quickHash(s,31,1e9+7)<<endl;
//   cout<<sh.getHash(0,2)<<endl;
// here in palinddrome the reverse hash and the forward hash of string comes equal
cout<<sh.getHash(0,s.size()-1)<<endl;
cout<<sh.getrevHash(0,s.size()-1)<<endl;


  

}
signed main(){
    solve();
}