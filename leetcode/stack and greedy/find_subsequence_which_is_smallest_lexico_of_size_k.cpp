// here we have to find the smallest lexicographically subsequence which is of k size

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod =1e9+7;
int k;
string smallestlexico_of_sizeK(string s) {
      map<char,int>mpp;
      vector<int>index(26,0);
      stack<char>st;
      int n=s.size();
      for(int i=0;i<s.size();i++){
        //here we are doing 
        // in stack always find the way to delete the element from stack and 
        // go in the direction of answer
        
            while(!st.empty()&&st.top()>s[i]&&st.size()-1+n-i>=k){
                st.pop();
            }
            if(st.empty()||st.size()<k){
            st.push(s[i]);
            }
      }
      string str="";
      while(!st.empty()){
        str+=st.top();
        st.pop();
      }
      reverse(str.begin(),str.end());
      return str;

        
        
}
void solve(){
    
    cin>>k;
    string s;
    cin>>s;
    cout<<smallestlexico_of_sizeK(s)<<endl;
   

}
signed main(){
    solve();

}