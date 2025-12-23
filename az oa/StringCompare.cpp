#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
string s,t;
cin>>s>>t;
string s1="";
string s2="";
for(int i=0;i<s.size();i++){
    if(s[i]!='#'){
        s1+=s[i];
    }else{
        if(!s1.empty()){
            s1.pop_back();
        }
    }
}
for(int i=0;i<t.size();i++){
    if(t[i]!='#'){
        s2+=t[i];
    }else{
        if(!s2.empty()){
            s2.pop_back();
        }
    }
}
if(s1==s2){
    cout<<"Yes"<<endl;
}else{
    cout<<"No"<<endl;
}
    

}
signed main(){
    solve();
}