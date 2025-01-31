#include<bits/stdc++.h>
using namespace std;
// #define int long long 
#define endl "\n"
string build(string s){
        string t;
        for(auto v:s){
            t+=string("#")+v;
        }
        t+="#";
        return (t);
    }
string longest(string t){
    vector<int>p;
    string s=build(t);
     int n=s.length();
        p.assign(n,1);
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
         
         int index=0;
         int maxi=0;
         for(int i=1;i<n-1;i++){
            if(p[i]>maxi){
                index=i;
                maxi=p[i];
            }
         }
        
         return t.substr((index+2-maxi)/2,maxi-1);
        

}
void solve(){
    string s;
    cin>>s;
    cout<<longest(s)<<endl;
    
  

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}