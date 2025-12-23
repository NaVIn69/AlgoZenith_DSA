#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int binary_expontiation(int a,int b,int mod){

  int ans=1;

  while(b){
  
  if(b%2 == 1){
    ans=((a%mod)*(ans%mod)) %mod;
  }
  a= ((a%mod)*(a%mod))%mod;
  b/=2;

  }
  return ans;
}
void solve(){
  string s;
  cin>>s;
  int freq[26]={0};
  for(int i=0;s[i]!='\0';i++){
    freq[s[i]-'a']++;
  }
  string even_occ_first="";
  string even_occ_last="";
  for(int i=0;i<26;i++){
    int k=freq[i];
    if(k>=2){
    int cnt=k/2;
    char ch=i+97;
    while(cnt--){
      even_occ_first+=ch;
      even_occ_last+=ch;
    }
    freq[i]=k%2;
    }

  }
  // for least 
  for(int i=0;i<26;i++){
       if(freq[i]==1){
        even_occ_last+=char(i+97);
        break;
       }
  }
  reverse(even_occ_last.begin(),even_occ_last.end());
  string ans=even_occ_first+even_occ_last;
  cout<<ans<<endl;


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