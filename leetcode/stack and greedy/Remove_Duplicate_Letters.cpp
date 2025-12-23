/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is 
the smallest in lexicographical order
 among all possible results.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
string removeDuplicateLetters(string s) {
       vector<bool>vis(26,false);
       vector<int>index(26,0);

       for(int i=0;i<s.size();i++){
           index[s[i]-'a']=i;
           vis[s[i]-'a']=true;
       }

       string ans="";
       stack<char>st;
       for(int i=0;i<s.size();i++){
          
          if(vis[s[i]-'a']==true){
          while(!st.empty()&&st.top()>s[i]&&index[st.top()-'a']>i&&vis[st.top()-'a']!=true){
            vis[st.top()-'a']=true;
            st.pop();
          }
          }
          if(vis[s[i]-'a']==true){
          st.push(s[i]);
          vis[s[i]-'a']=false;
          }
          
       }
       while(!st.empty()){
        cout<<st.top()<<" ";
         ans+=st.top();
         st.pop();
       }
       reverse(ans.begin(),ans.end());
       return ans;
        
        
}
void solve(){
    string s;
    cin>>s;
    cout<<removeDuplicateLetters(s)<<endl;

}
signed main(){
    solve();

}