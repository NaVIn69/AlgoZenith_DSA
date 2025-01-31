#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
 int n,k;
 cin>>n>>k;
 string s;
 cin>>s;
 vector<int>is_present(26,0);
 for(int i=0;i<k;i++){
    char ch;
    cin>>ch;
    is_present[ch-'a']=1;
 }
 int ans=0;
 int cnt=0;
 for(int i=0;i<n;i++){
   if(is_present[s[i]-'a']){
    cnt++;
   }else{
    ans+=((cnt*(cnt+1))/2);
    cnt=0;
   }
 }
 ans+=((cnt*(cnt+1))/2);
 cout<<ans<<endl;
}
signed main(){
    solve();
}