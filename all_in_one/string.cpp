#include<bits/stdc++.h>
using namespace std;
#define int long long

struct hasher{
    int sz,p,mod;
    // p-> prime 
    vector<int>fhash,revhash,powk;
    void init(string s,int p_,int mod_){
        sz=s.size();
        p=p_;
        mod=mod_;
        fhash.resize(n);
        revhash.resize(n);
        powk.resize(n+1);
        fhash[0]=s[i]-'a'+1;// here we are doing +1 make difference of a ,"aa"
        powk[0]=1;
        for(int i=1;i<sz;i++){
            fhash[i]=(((fhash[i-1]*p)%mod)+(s[i]-'a'+1)+mod)%mod;
            powk[i]=(powk[i-1]%mod*p)%mod;
        }
        revhash[sz-1]=s[sz-1]-'a'+1;
        for(int i=n-2;i>=0;i--){
            revhash[i]=(((revhash[i+1]*p)%mod)+(s[i]-'a'+1)+mod)%mod;
        }
    }

    int getfhash(int l,int r){
        if(l==0) return (fhash[r]%mod+mod)%mod;
        return ((fhash[r]-(fhash[l-1]*powk[r-l+1])%mod+mod))%mod;
    }
    int getrevhash(int l,int r){
        if(l==0) return (revhash[r]%mod+mod)%mod;
        return ((revhash[r]-(revhash[l-1]*powk[r-l+1])%mod+mod))%mod; 
    }
}

struct double_hash{
    hasher a,b;
    void init(string s){
        a.init(s,37,1e9+21);
        b.init(s,39,1e9+7);
    }
    pair<int,int>gethash(int l,int r){
        return {a.gethash(l,r),b.gethash(l,r)};
    }
    pair<int,int>getrevhash(int l,int r){
        return {a.getrevhash(l,r),b.getrevhash(l,r)};
    }
    bool is_palin(int l,int r){
        return gethash(l,r)==getrevhash(l,r);
    }

 };

 

void solve(){

}
int main(){
    solve();
}