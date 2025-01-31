#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    string s;
    cin>>s;
    int depth=0;
    bool is_balanced =false;
    int count[s.size()+2];
    count[0]=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            if(depth>=0){
                depth++;
            }else{
                depth++;
                is_balanced=false;
            }
        }else{
            depth--;
        }
        count[i]=depth;
    }
cout<<is_balanced<<endl;
for(int i=0;i<s.size()+2;i++){
    cout<<count[i]<<" ";
}
cout<<endl;
}

signed main(){
    solve();
}