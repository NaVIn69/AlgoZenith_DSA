#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;

void solve(){
    int p;
    cin>>p;
  queue<int>q;
   while(p--){
    string s;
    cin>>s;
    if(s=="add"){
        int x;
        cin>>x;
        q.push(x);
    }else if(s=="remove"){
       if(!q.empty()){
        q.pop();
       }
    }else if(s=="print"){
       cout<<q.front()<<endl;
       
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