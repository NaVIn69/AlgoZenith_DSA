#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void insertatBottom(stack<int>&st,int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int num=st.top();
    st.pop();
    insertatBottom(st,x);
    st.push(num);

}
void insertjustgreater(stack<int>&st,int x){
    if(st.empty() || st.top()<=x){
        st.push(x);
        return ;
    }
    int num=st.top();
    st.pop();
    insertjustgreater(st,x);
    st.push(num);
}

void Sort(stack<int>&st){
    if(st.empty()){
        return;
    }
    int num=st.top();
    st.pop();
    sort(st);
    insertjustgreater(st,num);
}

void Reverse(stack<int>&st){
     if(st.empty()){
        return ;
     }
     int num=st.top();
     st.pop();
     Reverse(st);
     insertatBottom(st,num);
}

void solve(){

}
signed main(){
    solve();
}