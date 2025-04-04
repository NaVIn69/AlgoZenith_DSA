// here we have given the n is upto 1o^12
// here we have to find all the factor of that number in the sorted order
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
void solve(){
 cin>>n;
 vector<int>ans;
 for(int i=1;i*i<=n;i++){
    if(n%i==0){
        ans.push_back(i);
        if(i*i!=n){
            ans.push_back(n/i);
        }
    }
 }
 sort(ans.begin(),ans.end());
 for(auto x:ans){
    cout<<x<<endl;
 }

}
signed main(){
    solve();
}