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
    string text,pattern;
    cin>>text>>pattern;
    hasher hash_text,hash_pattern;
    hash_text.init(text,37,1000000021);
    hash_pattern.init(pattern,37,1000000021);
    int n=text.length();
    int m=pattern.length();
    int needed=hash_pattern.gethash(0,m-1);
    // we are traversing the m window size of length
    for(int st=0;st+m-1<n;st++){
        if(hash_text.gethash(st,st+m-1)==needed){
            cout<<st<<" "<<st+m-1<<endl;
        }
    }
    
   
}
 
int main()
{
    solve();
    return 0;
}