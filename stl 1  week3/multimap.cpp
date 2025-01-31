#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;

void solve(){
    int p;
    cin>>p;
  multimap<string,int>q;
   while(p--){
    string s,name;
    cin>>s>>name;
    if(s=="add"){
        int marks;
        cin>>marks;
        q.insert({name,marks});

        
    }else if(s=="eraseall"){
      /*  auto it=q.find(name);
        if(it!=q.end()){
            q.erase(name);
        }*/
        q.erase(name);
        
       
    }else if(s=="print"){
        auto it=q.find(name);
        if(it!=q.end()){
            cout<<it->second<<endl;
        }else{
            cout<<"0"<<endl;
        }

      
       
    }else if(s=="erase"){
        auto it=q.find(name);
        if(it!=q.end()){
            q.erase(it);
        }
        
        
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