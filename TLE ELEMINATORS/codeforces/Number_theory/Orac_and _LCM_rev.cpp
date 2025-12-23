#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int gcd(int a,int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}
int lcm(int a,int b){
    int g=gcd(a,b);
    return (a*b)/g;
}
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n),prefix_gcd(n),suffix_gcd(n);
    for(int i=0;i<n;i++){
         cin>>arr[i];
         prefix_gcd[i]=arr[i];
         if(i){
          prefix_gcd[i]=gcd(prefix_gcd[i],prefix_gcd[i-1]);
         }
    }
    suffix_gcd[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffix_gcd[i]=gcd(suffix_gcd[i+1],arr[i]);
    }
    vector<int>g;
    
    for(int i=0;i<n;i++ ){
         if(i==0){
            int l=lcm(arr[i],suffix_gcd[i+1]);
            g.push_back(l);
         }else if(i==n-1){
            int l=lcm(arr[i],prefix_gcd[i-1]);
            g.push_back(l);
         }else{
             int g_without_i=gcd(prefix_gcd[i-1],suffix_gcd[i+1]);
             int l=lcm(g_without_i,arr[i]);
             g.push_back(l);
         }

    }
    int ans=gcd(g[0],g[1]);
    for(int i=0;i<g.size();i++){
        ans=gcd(ans,g[i]);
     
    }
    cout<<ans<<endl;


}
signed main(){
    solve();
}