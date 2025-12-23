#include<bits/stdc++.h>
using namespace std;
// #define int long long 
#define endl "\n"
struct manacher{
    vector<int>p;
     void run_manacher(string s){
        int n=s.length();
        p.assign(n,1); // radius at ith index 
        int l=1,r=1;
        // both l and r is exclusive 
        for(int i=1;i<n;i++){
            p[i]=max(0,min(r-i,p[l+r-i]));
            while(i+p[i]<n && i-p[i]>=0 && s[i-p[i]]==s[i+p[i]]){
                p[i]++;
            }
            if(i+p[i]>r){
            l=i-p[i];
            r=i+p[i];
            }
        }
        for(auto v:p){
            cout<<v<<" ";
        }
        cout<<endl;
     }
    void build(string s){
        string t;
        for(auto v:s){
            t+=string("#")+v;
        }
        run_manacher(t+"#");
    }
    // abbabba
    // char odd centred odd=1 ,, here we get the odd length palindrome
    // char ke bich even centred just uss center ke badd wla space here odd =0 // here we get the even length palindrome 
// this cen is in the main string
    int getlongest(int cen,bool odd){
        int pos=2*cen+1+(!odd);
        return p[pos]-1;
    }
  // both l and r have same parity then odd length
  // both l and r have differnt parity then even length
    bool checkpalin(int l,int r){
        if(r+l-1<=getlongest((r+l)/2,r%2==l%2)){
            return 1;
        }else{
            return 0;
        }
    }
}m;
void solve(){
    string s;
    cin>>s;
    m.build(s);
    cout<<m.checkpalin(1,5);

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}