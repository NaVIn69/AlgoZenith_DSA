#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void sorted_way(stack<int>&st,int x){
    if(st.empty() || st.top()<=x){
        st.push(x);
        return ;
    }
    int num=st.top();
    st.pop();
    sorted_way(st,x);
    st.push(num);

}
void sort_stack(stack<int>&st){
    if(st.empty()){
        return ;
    }
    int num=st.top();
    st.pop();
    sort_stack(st);
    sorted_way(st,num);
}
void solve(){

}
signed main(){
    solve();
}