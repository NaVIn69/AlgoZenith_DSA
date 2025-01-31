#include<bits/stdc++.h>
using namespace std;
void solve(){
int n;
cin>>n;
    int a[n];
    int b[n-1];
    int c[n-2];
    long long sum_a=0;
    long long sum_b=0;
    long long sum_c=0;
    for(int i=0;i<n;i++){
  cin>>a[i];
     sum_a+=a[i];   
    }
    for(int i=0;i<n-1;i++){
cin>>b[i];
        sum_b+=b[i];
    }
    for(int i=0;i<n-2;i++){
cin>>c[i];
        sum_c+=c[i];
    }
    cout<<sum_a-sum_b<<" "<<sum_b-sum_c<<endl;
        
}
int main(){
int t;
    cin>>t;
    while(t--){
solve();
cout<<min({0,0,0})<<endl;
    }

}