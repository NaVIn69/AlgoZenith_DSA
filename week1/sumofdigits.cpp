#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    long long sum=0;
   // string s="53453451234567876545676540909890989890987987567654567654567656765678765678765";
  for(int i=0;s[i]!='\0';i++){
  int k=s[i]-48;
      sum+=k;
  }
    cout<<sum<<endl;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}