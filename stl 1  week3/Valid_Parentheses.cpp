#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
 void solve(){
    string s;
    cin>>s;
    if(s.size()==0){
        cout<<"0"<<endl;
    }
    int cnt=0;
    int depth=0;
    bool flag=1;
    // for(auto v:s){
    //     if(v=='('){
    //         if(depth<0){
    //             cnt+=abs(depth);
    //             depth=1;
    //         }else{
    //             depth++;
    //         }
    //         }else if(v==')'){
    //             depth--; 
    //         }
    //     } 
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            if(depth<0){
                cnt+=abs(depth);
                depth=1;
            }else{
                depth++;
            }
        }else if(s[i]==')'&&s[i+1]==')'){
            i++;
            depth--;
        }
    }

        cnt+=abs(depth/2);
    
    cout<<cnt<<endl;
 }
 
 signed main(){
    ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
 }