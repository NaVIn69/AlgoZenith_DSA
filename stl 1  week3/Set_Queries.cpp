#include<bits/stdc++.h>
using namespace std;

void solve(){
   set<int>st,nst;
   int q;
   cin>>q;
   while(q--){
    int p,v;
    cin>>p>>v;
    if(p==1){
        st.insert(v);
        nst.erase(v);
        if(!st.count(v+1)){
            nst.insert(v+1);
        }
    }else{
     /**  int s=*st.begin();
        int e=*st.rbegin();
        if(v>e){
            cout<<v<<endl;
        }else if(v==e){
            cout<<v+1<<endl;
        }else if(v<s&&(v+1)!=s){
            cout<<(v+1)<<endl;
        }else{
            auto it=st.find(v);
            if(it==st.end()){
                cout<<v<<endl;
            }else{
              */
             if(!st.count(v)){
                cout<<v<<endl;
             }else{
                cout<<*nst.lower_bound(v)<<endl;
             }
  
    }

            
        }
    }
    
   

    
int main(){
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