#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    bool bl=((n-b)%2==0);
    bool check = false;
    if(bl){
        if(a<=b)check = true;                
        else if((n-a)%2==0)check = true;  
    }
    
    if(check){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
   
}

signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}