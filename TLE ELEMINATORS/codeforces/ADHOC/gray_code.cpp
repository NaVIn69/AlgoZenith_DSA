#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void print(int x){
    while(x){
        if(x&1){
            cout<<1;
        }else{
            cout<<0;
        }
       x=x>>1;
    }
    cout<<endl;
}
void solve(){
  int n;
  cin>>n;
  int tot=(1<<n)-1;
  for(int i=0;i<tot;i++){
      print(i);
  }
}
signed main(){
    solve();
}