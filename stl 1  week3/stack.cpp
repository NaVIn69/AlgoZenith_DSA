#include<bits/stdc++.h>
using namespace std;

void solve(){
    int p;
    cin>>p;
  stack<int>q;
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
        if(!q.empty()){
       cout<<q.top()<<'\n';
        }else{
            cout<<"0"<<'\n';
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