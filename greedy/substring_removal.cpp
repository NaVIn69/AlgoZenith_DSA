#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
   string s;
   cin>>s;
   int x,y;
   cin>>x>>y;
    int tot=0;
   // ab ko delete krne pe x coin
   // ba ko delete krne pe y coin
   int maxi=max(x,y);
   if(maxi==x){
    // first we delete the ab substring then after 
    // we delete the ba substring
    stack<int>st;
    // int tot=0;
    //ab
    for(int i=0;s[i]!='\0';i++){
        if(!st.empty()&&st.top()=='a'&&s[i]=='b'){
            tot+=x;
            st.pop();
            continue;
        }
        st.push(s[i]);
       
    }
   string str="";
    while(!st.empty()) {
        str+=st.top();
        st.pop();
    }
  
    reverse(str.begin(),str.end());
    
   for(int i=0;str[i]!='\0';i++){
        if(!st.empty()&&st.top()=='b'&&str[i]=='a'){
            tot+=y;
    
            st.pop();
            continue;;
        }
        st.push(str[i]);
   }
   

   }else{
      stack<int>st;
          for(int i=0;s[i]!='\0';i++){
        if(!st.empty()&&st.top()=='b'&&s[i]=='a'){
            tot+=y;
            st.pop();
            continue;
        }
        st.push(s[i]);
    }
    string str="";
    while(!st.empty()) {
        str+=st.top();
        st.pop();
    }
  
    reverse(str.begin(),str.end());
    
   for(int i=0;str[i]!='\0';i++){
        if(!st.empty()&&st.top()=='a'&&str[i]=='b'){
            tot+=x;
    
            st.pop();
            continue;;
        }
        st.push(str[i]);
   }

   }
   cout<<tot<<endl;
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