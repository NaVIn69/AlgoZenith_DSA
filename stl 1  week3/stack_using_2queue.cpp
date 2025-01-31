#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int q;
    cin>>q;
    stack<int>st1;
    stack<int>st2;
    while(q--){
        string s;
        cin>>s;
        if(s=="push"){
            int x;
            cin>>x;
            st1.push(x);
        }else if(s=="pop"){
            if(!st2.empty()){
                cout<<st2.top()<<endl;
                st2.pop();
            }else{
                while(!st1.empty()){
                    st2.push(st1.top());
                    st1.pop();
                }
                if(!st2.empty()){
                    cout<<st2.top()<<endl;
                    st2.pop();
                }
            }
           
            
        }else if(s=="front"){
            if(!st2.empty()){
                cout<<st2.top()<<endl;
            }else{
                while(!st1.empty()){
                    st2.push(st1.top());
                    st1.pop();
                }
                if(!st2.empty()){
                    cout<<st2.top()<<endl;
                }
            }
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(NULL);
    cout.tie(NULL);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}