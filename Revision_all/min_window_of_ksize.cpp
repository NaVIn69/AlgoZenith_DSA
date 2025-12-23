#include<bits/stdc++.h>
using namespace std;
// in fixed window size 
// first built the first window and then after built the second window
// total window of k size is (n-k+1)

void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    multiset<int>st;
    for(int i=0;i<k;i++){
      st.insert(arr[i]);
    }
    cout<<*st.begin()<<" ";
    for(int i=0;i<n-k;i++){
       auto it=st.find(arr[i]);
       st.erase(it);
       st.insert(arr[i+k]);
       cout<<*st.begin()<<" ";
    }
    cout<<endl;

}
int main(){
    solve();
}