#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void binary(int x){
    for(int i=63;i>=0;i--){
        if((x>>i)&1LL){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }
    cout<<endl;
}
int msb(int x){
    if(x==0) return -1;
    if(x<0) return 63;
    return __lg(x);
}
int rsb(int x){
    int k=x^(x-1);
    return msb(k);
}
bool is_power2(int x){
  if(x<=1) return -1;
  return (__builtin_popcountll(x)==1);
}
bool pow_div(int x){
if(x==0) return -1;
return (1LL<<__builtin_cl)
}

void solve(){
 int n;
 cin>>n;
  int q;
 
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}