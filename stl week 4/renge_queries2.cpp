#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define ii pair<int,int>
struct range_queries{
    set<ii>st;
    void fill_range(int l, int r){
        auto it=st.upper_bound({l,1e9});
        if(it!=st.begin()){
            it--;
            if(it->second>=l){
                l=it->first;
                r=max(r,it->second);
                st.erase(it);

            }
        }
        it=st.upper_bound({r,1e9});
        if(it!=st.begin()){
            it--;
            if(it->second>=r){
                r=it->second;
                l=min(lt->first,l);
                st.erase(it);
            }
        }
        // deleting the segment
        while(1){
            it=st.lower_bound({l,0});
            if(it==st.end()||it->first>r){
                break;
            }else{
                st.erase();
            }
        }
        st.insert({l,r});

    }
    void clear_range(int l,int r){



    }
    bool check_point(int x){
        auto it=st.upper_bound({x,1e9});
        if(it==st.begin()){
            return false;
        }else{
            it--;
            if(it->second>=x){
                return true;
            }else{
                return false;
            }
        }

    }
    bool check_for_range_any(int x,int y){
          auto it=st.upper_bound({x,1e9});
          if(it!=st.end()){
            if(it->first<=y){
                return true;
            }
          }
          return check_point(x);

    }
    bool check_for_all(int x,int y){
        auto it=st.upper_bound({x,1e9});
        if(it==st.begin()){
            return false;
        }else{
            it--;
            if(it->second>=y){
                return true;
            }else{
                return false;
            }
        }

    }


};
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