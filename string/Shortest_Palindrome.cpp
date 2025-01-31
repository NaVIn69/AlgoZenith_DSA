#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct hasher{
    int n, _k, _p;
    vector<int> powk,base,rev;
 
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
        //rev;
        rev.resize(n+1);
        rev[n]=0;
        for(int i=n-1;i>=0;i--){
            int num = (s[i]-'a'+1 )%p;
            rev[i] = (1LL *rev[i+1] * k + num)%p;
        }

    }  
    int gethash(int l,int r){ // 0 index
        int ans = (base[r+1] - 1LL *base[l]*powk[(r-l+1)])%_p;
        return (ans+_p)%_p;
    }
    int getrevhash(int l,int r){ // 0 based index
         int ans = (rev[l] - 1LL *rev[r+1]*powk[(r-l+1)])%_p;
        return (ans+_p)%_p;
    }
};
 
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
  string s;
  cin>>s;
  int n=s.size();
  // find the longest palindrome substring present inthe string
  // use bs on length and comapre with hash value
  //
  double_hash myhs;
  myhs.init(s);
  int l=1;
  int h=n;
  int ans=0;
  while(l<=h){
    int mid=l+(h-l)/2;
    int mid1=mid+1;
    bool check=false;
    for(int i=0;i+mid-1<n;i++){
        if(myhs.gethash(i,i+mid-1)==myhs.getrevhash(i,i+mid-1)){
            check=true;
            break;
        }
    }
    bool check2=false;
    for(int i=0;i+mid1-1<n;i++){
        if(myhs.gethash(i,i+mid1-1)==myhs.getrevhash(i,i+mid1-1)){
            check2=true;
            break;
        }
    }

    if(check2){
        ans=mid1;
        l=mid1+1;
    }else if(check){
         ans=mid;
         l=mid+1;
    }else{
        h=mid-1;
    }

  }
  cout<<ans<<endl;
}
signed main(){
    solve();
}