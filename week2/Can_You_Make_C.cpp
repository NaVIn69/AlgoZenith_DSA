#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a,int b){
 
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
    
}
   
void solve(){
int a,b,c;
cin>>a>>b>>c;
int gcd_of_number=gcd(a,b);
cout<<gcd_of_number<<" ";
if(c%gcd_of_number==0){
    cout<<"Yes"<<endl;
}else{
    cout<<"No"<<endl;
}
/// if lcm of c/a and c/b is integer then we get integer solution



}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}