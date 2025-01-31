#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    // first we to find the array which store the minimum elem from index i to end of string
    // 2 -> we have to compare the top of stck with arr[i](minimum of char from i to end of string)
    string s;
    cin>>s;
    int n=s.size();
    // making array which store the minimum char from index i to end of string
    vector<char>v(n);
    v[n-1]=s[n-1];
    for(int i=n-2;i>=0;i--){
        if(s[i]<v[i+1]){
            v[i]=s[i];
        }else{
            v[i]=v[i+1];
        }
    }
    // traversing the string 
    string ans="";
    stack<char>st;
    for(int i=0;i<n;i++){
        if(i==0){
            st.push(s[i]);
        }else{
            while(!st.empty()&& st.top()<=v[i]){
                ans+=st.top();
                st.pop();

            }
            st.push(s[i]); // here we are making t string
        }
    }
    // when string s is going to empty
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    cout<<ans<<endl;


}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}