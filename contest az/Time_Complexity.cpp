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
stack<string>st;
if(s[0]=='e'){
    cout<<"Compile Error"<<endl;
    return;
}
int n=s.size();
string ans="";
for(int i=0;s[i]!='\0';){
    if(s[i]=='f'){
         st.push("for");
         i=i+3;
    }else{
        if(st.empty()){
            cout<<"Compile Error"<<endl;
            return ;
        }
        int cnt=0;

        while(!st.empty()&&s[i]=='e'){
            st.pop();
            cnt++;
            i=i+6;
        }
        if(ans.size()==0){


        }
        else{
            if(cnt==1){
            


            }else{     
          int index=ans.find(to_string(cnt));
          if(index != string::npos){
           // string me mil gaya
           if(ans[index-1]=='^'){
            int val=ans[index-1];
            cnt+=val;
            string update=ans.insert(index,to_string(cnt));
           }

          }else{

          }


        }
       
        
    }

}
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