#include<bits/stdc++.h>

using namespace std;
#define int long long
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

void solve(){
    int q;
    cin>>q;


     set<int>st;
    while(q--){
        string s;
        int x;
        cin>>s>>x;

        if(s=="add"){
            if(st.find(x)==st.end()){
          st.insert(x);

        }else if(s=="remove"){
            auto it=st.find(x);
            if(it!=st.end()){
                st.erase(x);
            }
        }else if(s=="find"){
            if(x>=st.size()){
                cout<<"-1"<<endl;
            }else{
                auto it=st.begin();
                int cnt=0;
                while(it!=st.end()){

                }
            }
        }

    }



}
signed mani(){
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
