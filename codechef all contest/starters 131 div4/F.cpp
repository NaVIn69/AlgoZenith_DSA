
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
bool isgood(int n){
    while(n>0){
        int rem=n%3;
        if(rem==2) return true;
        n=n/3;
    }
    return false;
}
void solve(){
  int n;
  cin>>n;
  if(isgood(n+1)){
    // here we have to make p[i]+i=n+1 means reverse array
    for(int i=n;i>=1;i--){
        cout<<i<<" ";
    }
    cout<<endl;
    return;
  }else if(isgood(n)){
    // here p[i]+i=n  n-1 +1 =n
     for(int i=n-1;i>=1;i--){
        cout<<i<<" ";
     }
     cout<<n<<endl;
     return;
     
  }else{
    // here if n  and n+1 is not good then n-1 must be the good number
      //p[i]+i=n-1;
      //n-2+1=n-1
      for(int i=n-2;i>=1;i--){
        cout<<i<<" ";
      }
      cout<<n<<" "<<n-1<<endl;
      return;
  }


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}