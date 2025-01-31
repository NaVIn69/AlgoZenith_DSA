#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
 
void solve(){
    int q;
    cin>>q;
    ordered_set st;

    while(q--){
        string s;
        cin>>s;
        if(s=="add"){
            int x;
            cin>>x;
            st.insert(x);
        }
        if(s=="find"){
            int x;
            cin>>x;
            auto it=st.find_by_order(x);
            if(it!=st.end()){
                cout<<*it<<endl;
            }
            else cout<<-1<<endl;
        }
        if(s=="findpos"){
            int x;
            cin>>x;
            
            cout<<st.order_of_key(x)<<endl;;

        }
        if(s=="remove"){
            int x;
            cin>>x;
            st.erase(x);
        }
    }
}   
 
 
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);cout.tie(NULL);

    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}