#include<bits/stdc++.h>
using namespace std;

void solve(){
    
    int q;
    cin>>q;
   vector<int>v;
   while(q--){
    int x;
    string s;
    cin>>s;
    if(s=="add"){
        cin>>x;
        v.push_back(x);
    }else if(s=="remove"){
        if(v.size()!=0){
            v.pop_back();
        }
    }else if(s=="print"){
        cin>>x;
        if(x>=v.size()||v.size()==0){
            cout<<"0"<<endl;
        }else{
            cout<<v[x]<<endl;
        }
    }else{
        v.resize(0);
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