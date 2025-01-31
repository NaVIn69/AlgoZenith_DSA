#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;

void solve(){
    int p;
    cin>>p;
  multiset<int>q;
   while(p--){
    string s;
    cin>>s;
    if(s=="add"){
        int x;
        cin>>x;
        q.insert(x);
    }else if(s=="eraseall"){
        int x;
        cin>>x;
       
        q.erase(x);
       
    }else if(s=="print"){
       for(auto it=q.begin();it!=q.end();it++){
        cout<<*it<<" ";
       }
       cout<<endl;
       
    }else if(s=="erase"){
        int x;
        cin>>x;
        auto it=q.find(x);
        if(it!=q.end()){
            q.erase(q.find(x));
        }
    
        
    }else if(s=="count"){
        int x;
        cin>>x;
        cout<<q.count(x)<<endl;
    }else if(s=="find"){
        int x;
        cin>>x;
        auto it=q.find(x);
        if(it!=q.end()){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }else{
        q.clear();
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
    
}