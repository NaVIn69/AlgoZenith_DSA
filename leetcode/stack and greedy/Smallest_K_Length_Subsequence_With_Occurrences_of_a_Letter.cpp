// in that question first we have to find the lexicographical smallest subsequence of length m and we have letter which has repetation is atleast k time

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod =1e9+7;
int k;
char ch;
int rep;
// at least ch rep times hona chahiye smallest lexicographical subsequence me


string smallestlexico_of_sizeK(string s) {
    int tot_ch=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]==ch)tot_ch++;
    }
   stack<char>st;
   int curr_ch=0;
   // here st_ch tells me about that how many letters are present in the stack
   // there are so many letter which is present which is not in the stack and neither in the right side of i 
   // we have to count that letter
   int nan_ch=0;
   int st_ch=0;
   for(int i=0;i<n;i++){
     int rem_ch=tot_ch-st_ch-nan_ch;
     // here rem_ch tells me about the how many letters present in the right side of i
    // if(st_ch==0&& st.top()<s[i]){
    //     while(!st.empty()&&st.size()+rem_ch<=rep){
    //         st.pop();
    //     }
    // }else{
      while(!st.empty()&&(st.top()>s[i])&&st.size()-1+n-i>=k){
          if(st.top()==ch&&rem_ch+st_ch-1>=rep){
            st_ch--;
            nan_ch++;
            rem_ch=tot_ch-st_ch-nan_ch;
            st.pop();
          }else if(st.top()!=ch){
            st.pop();
          }else {
            break;
          }
      }
    
     
      
      if(st.empty()||(st.size()<k)){
        // if(s[i]==ch&&tot_ch-nan_ch>=rep)
        if(s[i]==ch){
            st_ch++;
        }
        st.push(s[i]);
      }
   }
   string ans="";
   while(!st.empty()){
    ans+=st.top();
    st.pop();
   }
   reverse(ans.begin(),ans.end());
   return ans;
        
}
void solve(){
    
    cin>>k>>rep>>ch;
    string s;
    cin>>s;
    cout<<smallestlexico_of_sizeK(s)<<endl;
   

}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }

}