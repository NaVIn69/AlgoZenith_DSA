#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    int x[n],y[n];
    for(int i=0;i<n;i++){
        int x1,y1;
        cin>>x1>>y1;
        x[i]=x1;
        y[i]=y1;
    }
    // here we have to find the minimum distance sum(abs(x-xi)+abs(y-yi))
    sort(x,x+n);
    sort(y,y+n);
    int median_index_axis=n/2;
    int val_x=x[median_index_axis];
    int val_y=y[median_index_axis];

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=abs(x[i]-val_x);
        sum+=abs(val_y-y[i]);
    }
    cout<<sum<<endl;

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