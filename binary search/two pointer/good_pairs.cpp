#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int c[n];
    for(int i=0;i<n;i++){
        c[i]=a[i]-b[i];
    }
    sort(c,c+n);
    
    //cout<<endl;
    int cnt=0;
    for(int i=0;i<n-1;i++){
      int find=-c[i];
      // cout<<find<<endl;
      // HERE WE have been done c[i]+c[j]>0 and i pe bhi index aa skta then we do i+1;
        int index=upper_bound(c+i+1,c+n,find)-c;
        
        cnt+=(n-index);
    }
   cout<<cnt<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}