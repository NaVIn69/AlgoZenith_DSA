#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int q;
    cin>>q;
    deque<int>dq;
    while(q--){
        string s;
        cin>>s;
        if(s=="insertback"){
            int x;
            cin>>x;
            dq.push_back(x);

        }else if(s=="eraseback"){
            if(!dq.empty()){
                dq.pop_back();
            }
        }else if(s=="insertfront"){
            int x;
            cin>>x;
            dq.push_front(x);
        }else if(s=="printfront"){
            if(!dq.empty()){
                cout<<dq.front()<<endl;
            }else{
                cout<<"0"<<endl;
            }
        }else if(s=="printback"){
            if(!dq.empty()){
                cout<<dq.back()<<endl;
            }else{
                cout<<"0"<<endl;
            }
        }else{
            int x;
            cin>>x;
            if(x>=dq.size()){
                cout<<"0"<<endl;
            }else{
                cout<<dq[x]<<endl;
            }
        }
    }

}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}