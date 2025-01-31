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
    string s;
    cin>>s;
    hasher hasha,hashb;
    hasha.init(s,31,1e9+7);
    hashb.init(s,39,1e9+9);
    set<pair<int,int>>st;
    for(int i=0;i<s.length();i++){
        for(int j=i;j<s.length();j++){
            st.insert({hasha.gethash(i,j),hashb.gethash(i,j)});
        }

    }
    cout<<st.size()<<endl;
   
}
 
int main()
{
    solve();
    return 0;
}