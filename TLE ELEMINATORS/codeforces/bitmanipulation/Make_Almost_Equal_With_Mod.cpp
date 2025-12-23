// if we divided a number 2^k then as a remainder we get only k bit representation
// to get 2 distnict we only have to get 3 bit , on three 23 can get 2 distnict number
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n;
int arr[1000];
void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  for(int i=1;i<61;i++){
       int num=(1LL<<i);
       set<int>st;
       for(int i=0;i<n;i++){
         st.insert(arr[i]%num);
       }
       if(st.size()==2){
         cout<<num<<endl;
         return ;
       }
  }


}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}