#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    string s;
    cin>>s;
    int q;
    cin>>q;
   while(q--){
    int n;
    cin>>n;
    if(n==1){
        int i;
        cin>>i;
        char ch;
        cin>>ch;
        s[i-1]=ch;
    }else{
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        unordered_map<char,int>mpp;
        for(int i=l;i<=r;i++){
            mpp[s[i]]++;
        }
        cout<<mpp.size()<<endl;
        
    }
   }
    

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