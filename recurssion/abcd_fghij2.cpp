#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
   int n;
   cin>>n;
   // abcde=n*fghij
   // here we are optimising the solution by like that fghij has <=5 integer then max value is 99999
   // here we geberate then check 
   for(int fghij=1234;fghij<=99999/n;fghij++){
      int abcde=n*fghij;
      int temp=abcde;
      set<int>st;
      for(int i=0;i<5;i++){
        st.insert(temp%10);
        temp/=10;
      }
      temp=fghij;
      for(int i=0;i<5;i++){
        st.insert(temp%10);
        temp/=10;
      }
      if(st.size()==10){
        cout<<abcde<<" "<<fghij<<endl;
      }
   }


}
signed main(){
    solve();
}