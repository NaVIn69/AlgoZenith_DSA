#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;

void solve(){
    int q;
    cin>>q;
    set<int>st;
    while(q--){
        string s;
        cin>>s;
        if(s=="add"){
            int x;
            cin>>x;
            st.insert(x);
        }else if(s=="erase"){
            int x;
            cin>>x;
            st.erase(x);
        }else if(s=="find"){
            int x;
            cin>>x;
            auto it=st.find(x);
            if(it!=st.end()){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else if(s=="print"){
            for(auto it=st.begin();it!=st.end();it++){
                cout<<*it<<" ";
            }
            cout<<endl;
        }else{
            st.clear();
        }
    }
 
}
    
signed main(){
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
    
}