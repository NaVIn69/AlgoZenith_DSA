#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int arr[10]={0,9,9,9,9,9,9,9,9,9};

int Size(int x){
    int cnt=0;
    while(x!=0){
        cnt++;
        x/=10;
    }
    return cnt;
}
vector<int>equal_size(int sz){
    vector<int>ans;
    for(int i=1;i<=9;i++){
        int x=sz;
        int val=0;
        while(x--){
            val=val*10+i;
        }
        ans.push_back(val);
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    if(n<=9){
        cout<<n<<endl;
        return ;
    }
    int sz=Size(n);
    // cout<<sz<<endl;
    int val=(sz-1)*arr[sz-1];
    //cout<<val<<endl;
    vector<int>comp=equal_size(sz);
    int idx=lower_bound(comp.begin(),comp.end(),n)-comp.begin();
    if(comp[idx]==n){
    cout<<val+idx+1<<endl;
    }else{
        cout<<val+idx<<endl;
    }


}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}