#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
int n,m,p;
cin>>n>>m>>p;
int a[n][m],b[m][p],c[n][p];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>a[i][j];
    }
}
for(int i=0;i<m;i++){
    for(int j=0;j<p;j++){
        cin>>b[i][j];
    }
}
for(int i=0;i<n;i++){
    for(int k=0;k<p;k++){
        int sum=0;
    for(int j=0;j<m;j++){
     sum+=(a[i][j]*b[j][k]);
    }
    c[i][k]=sum;
    }

}
for(int i=0;i<n;i++){
    for(int j=0;j<p;j++){
        cout<<c[i][j]<<" ";
    }
    cout<<endl;
}
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cout.tie(NULL);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
   solve();
    }
}