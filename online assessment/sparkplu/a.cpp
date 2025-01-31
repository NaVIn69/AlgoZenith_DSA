#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    string st;
     int k;
    cin>>st>>k;
    int sz= st.size();
    vector<int>arr;
    for( int i=0;i<sz;i++){
         arr.push_back(st[i]-'0');
    }
    vector<int>odd;
    for( int i=0;i<sz;i++){
        if(arr[i]%2){
            odd.push_back(i+1);
        }
    }
    int tot=0;
    for(auto x:odd){
        tot+=x;
    }
    if(tot<=k){
        cout<<0<<endl;
        return ;
    }
    int more=tot-k;
    int j=odd.size()-1;
    int cnt=0;
    while(more>0){
         more-=odd[j];
         j--;
         cnt++;
         
    }
    cout<<cnt<<endl;
    
    
}
signed main(){
    solve();
    return 0;
}
    