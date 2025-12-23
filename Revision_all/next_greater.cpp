#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100100];
int next_greater[100100];
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<int>st;
    for(int i=n-1;i>=0;i--){
          while(!st.empty()&&st.top()<=arr[i]){
              st.pop();
          }
          if(st.empty()){
            next_greater[i]=-1;
          }else{
            next_greater[i]=st.top();
          }
          st.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<next_greater[i]<<" ";
    }
    cout<<endl;


}
int main(){
    solve();
}