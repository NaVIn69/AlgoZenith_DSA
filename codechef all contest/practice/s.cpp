#include<bits/stdc++.h>
using namespace std;
void solve(){
int n;
cin>>n;
int arr[n];
int cnt=0;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
for(int i=n-1;i>=0;i--){
    if(arr[i]%2==0){
        cnt+=(i+1);
       // cout<<i+1<<endl;
    }
}
stack<int>st;
vector<int>v;
//vector<int>v1;
for(int i=0;i<n;i++){
    if(arr[i]%2==0){
        st.push(i);
        continue;
    }
    while(!st.empty()&&arr[st.top()]%2!=0){
        st.pop();
    }
    if(st.empty()){
         v.push_back(-1);
    }else{
        v.push_back(st.top());

    }
    st.push(i);
}
vector<int>v1;
stack<int>st1;
for(int i=n-1;i>=0;i--){
    if(arr[i]%2==0){
        st1.push(i);
        continue;
    }
    while(!st1.empty()&&arr[st1.top()]%2!=0){
        st1.pop();
    }
    if(st1.empty()){
         v1.push_back(-1);
    }else{
        v1.push_back(st1.top());

    }
    st.push(i);
}
int cnt1=cnt;
int index=0;
for(int i=n-1;i>=0;i--){
 if(arr[i]%2==1){
    index=i;
    cnt+=(i+1);
    //cout<<i+1<<endl;
    break;
 }
}
 int idx=0;
   for(int i=0;i<n;i++){
          if(arr[i]%2==1){
            idx=i;
            cnt1+=(n-i+1);
            break;
          }
   }
 
for(int i=idx+1;i<v1.size();i++){
    cout<<v1[i]<<" ";
 if(v1[i]!=-1) cnt1+=(v1[i]+1);
}
for(int i=v.size()-2;i>=0;i--){
    if(v[i]!=-1) cnt+=(v[i]+1);
   // cout<<v[i]+1<<endl;
}
cout<<max(cnt,cnt1)<<endl;



}
int main(){
    int t;
    cin>>t;
    while(t--){
    solve();}
}