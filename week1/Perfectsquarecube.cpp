#include<bits/stdc++.h>
using namespace std;
bool check_cube(int n){
      int s=2;
    int e=n;
    while(s<=e){
       int mid=s+(e-s)/2;
       long long m=mid*mid*mid;
       if(m==n){
        return true;
       }else if(m>n){
        e=mid-1;
       }else{
        s=mid+1;
       }
    }
    return false;
}
bool check_square(int n){
    int s=2;
    int e=n;
    // bool ans=false;
    while(s<=e){
       int mid=s+(e-s)/2;
       long long m=mid*mid;
       if(m==n){
       return true;
       }else if(m>n){
        e=mid-1;
       }else{
        s=mid+1;
       }
    }
    return false;
}
void solve(){
    int q,n;
    cin>>q>>n;
    bool ans=false;
    if(n==1){
        cout<<"YES"<<endl;
        return;
    }
    if(q==1){
         ans=check_square(n);
    }else{
        ans=check_cube(n);
    }
    if(ans){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}