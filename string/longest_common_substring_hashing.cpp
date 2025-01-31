// here we have to find the longest common substring

#include<bits/stdc++.h>
using namespace std;
 
struct hasher{
    int n, _k, _p;
    vector<int> powk,base;
 
    void init(string s,int k,int p){
        _k = k, _p = p;
        n = s.length();
        powk.resize(n+1);
        base.resize(n+1);
        // precompute
        base[0] = 0;
        powk[0] = 1;
        for(int i=0;i<n;i++){
            int num = (s[i]-'a'+1 )%p;
            base[i+1] = (1LL *base[i] * k + num)%p;
            powk[i+1] = (1LL* k * powk[i]) %p;
        }
    }  
    int gethash(int l,int r){ // 0 index
        int ans = (base[r+1] - 1LL *base[l]*powk[(r-l+1)])%_p;
        return (ans+_p)%_p;
    }
};
 
void solve(){
    string a,b;
    cin>>a>>b;
    // here we using binary search on the length

    hasher hasha,hashb;
    hasha.init(a,39,1e9+7);
    hashb.init(b,39,1e9+7);
    int n=min(a.length(),b.length());
    int lo=1;
    int hi=n;
    int ans=0;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        // here we have check every string length of mid size in both string
        // if they are true then we go for bigger length
        bool check=false;
        set<int>st1;
        for(int st=0;st+mid-1<a.length();st++){
            st1.insert(hasha.gethash(st,st+mid-1));
        }
        
        for(int st=0;st+mid-1<b.length();st++){
            int hash=hashb.gethash(st,st+mid-1);
            if(st1.find(hash)!=st1.end()){
                check=true;
                break;
            }
        }

        if(check){
            ans=mid;
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    cout<<ans<<endl;
   
}
 
int main()
{
    solve();
    return 0;
}