// #include<bits/stdc++.h>

#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
using ld=long double;
 
  
void solve(){
lli n;
ld m;
cin>>n>>m;
string str;
cout<<str<<endl;
string d=to_string(m);
cout<<d<<endl;
string str3="";
lli num_beforedecimal=0;
lli num_afterdecimal=0;
for(int i=0;i<str[i]!='\0';i++){
    if(str[i]!='.'){
        str3+=str[i];
    }else{
    stringstream ss1;
    ss1<<str3;
    ss1>>num_beforedecimal;
     str3.erase();
     str3="";
    }
}
cout<<str3<<endl;
num_afterdecimal=stof(str3);
cout<<num_afterdecimal<<" "<<num_afterdecimal<<'\n';
// if(n==0&&num_afterdecimal==0){
//     cout<<"0"<<"."<<(num_beforedecimal+n)<<'\n';
// }else{
    cout<<(n+num_afterdecimal)<<"."<<(n+num_beforedecimal)<<'\n';


}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}