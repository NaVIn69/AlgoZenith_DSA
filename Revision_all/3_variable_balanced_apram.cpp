#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    string s;
    cin>>s;
    map<char,int>mpp;
    mpp['(']=1;
    mpp['{']=2;
    mpp['[']=3;
    mpp[')']=-1;
    mpp['}']=-2;
    mpp[']']=-3;
    stack<char>st;
    for(int i=0;i<s.size();i++){
        int x=mpp[s[i]];
        if(x > 0){
            // opeening bracket
            st.push(x);
        }else if(st.top()+mpp[s[i]]==0){
                  st.pop();
        }else{
            cout<<"invalid"<<endl;
            return;
        }
    }
    if(!st.empty()){
        cout<"<invalid"<<endl;
        return ;
    }



}
signed main(){
    solve();
}