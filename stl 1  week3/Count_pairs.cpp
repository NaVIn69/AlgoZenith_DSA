#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]>x) break;
        int find=x-a[i];
        
        int number_of_ele=upper_bound(a,a+i,find)-a;
        
        cnt+=(2*number_of_ele);
    }
    cout<<cnt<<endl;
    
        
   

}
signed main(){
   ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}