#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
int n;
cin>>n;
int a[n];
int b[n];
for(int i=0;i<n;i++){
    cin>>a[i];
    b[i]=a[i];
}
sort(b,b+n);
int pre[100100]={0};
pre[0]=1;
while(next_permutation(b,b+n)){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            cnt++;
        }
    }
   
    pre[cnt]=cnt;
    
}
for(int i=1;i<n;i++){
    pre[i]+=pre[i-1];
    pre[i]=pre[i]%mod;
}
int q;
cin>>q;
while(q--){
    int k;
    cin>>k;
    cout<<(pre[k]%mod+mod)%mod<<endl;
}

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}