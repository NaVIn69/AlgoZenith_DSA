#include<bits/stdc++.h>
using namespace std;
#define int long long

 int mod=1e9+7;
  
void solve(){
int q;
cin>>q;
int sum=0;
map<int,int>mpp;
while(q--){
    int n;
    cin>>n;
    if(n==1){
        int x;
        cin>>x;
        sum+=x;
        mpp[x]++;
    }else if(n==2){
        int x;
        cin>>x;
  if(mpp.find(x)!=mpp.end()){
      sum-=x;
        mpp[x]--;
        if(mpp[x]==0) mpp.erase(x);
  }
    }else if(n==3){
        char ch;
        cin>>ch;
        if(!mpp.empty()){
        cout<<mpp.begin()->first<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }else if(n==4){
        char ch;
        cin>>ch;
        if(!mpp.empty()){
        cout<<mpp.rbegin()->first<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }else if(n==5){
        char ch;
        cin>>ch;
        if(!mpp.empty()){
            cout<<sum<<endl;
        }else{
            cout<<"0"<<endl;
        }
    }
}

}
signed main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
    int t=1;
     cin>>t;
     while(t--){
        solve();
     }
}