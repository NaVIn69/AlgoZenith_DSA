#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
    string t;
    cin>>t;
   // here we count the non 'a' character in the left side
   int non_a_prefix=0;
   int non_a_suffix=0;
   int n=t.size();
   bool check=true;// first a ke badd non a character
   for(int i=n-1;i>=0;i--){
       if(check==false&&t[i]!='a'){
        non_a_prefix++;
       }
      else if(check==true&&t[i]!='a'){
        non_a_suffix++;
       }else if(t[i]=='a'){
        check=false;
       }
   }
   if(non_a_suffix<non_a_prefix){
    cout<<":("<<endl;
    return ;
   }
//    cout<<non_a_prefix<<" "<<non_a_suffix<<endl;
   while(non_a_suffix>non_a_prefix){
        non_a_suffix--;
        non_a_prefix++;
   }
   string str_suffix=t.substr(n-non_a_suffix,non_a_suffix);
   int len=n-non_a_suffix;
    string str_prefix="";
   for(int i=0;i<len;i++){
    if(t[i]!='a'){
       str_prefix+=t[i];
    }
   }
   if(str_prefix==str_suffix){
    cout<<t.substr(0,len)<<endl;
   }else{
    cout<<":("<<endl;
   }
   

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}