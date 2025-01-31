#include<bits/stdc++.h>
using namespace std;

void solve(){
   int n;
   cin>>n;
   
   unordered_map<string,int>mpp;
   while(n--){
    string s;
   cin>>s;
    if(mpp.find(s)!=mpp.end()){
        
        cout<<s<<mpp[s]<<endl;
        mpp[s]++;
    }else{
        cout<<"OK"<<endl;
        mpp[s]++;
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