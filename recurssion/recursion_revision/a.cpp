#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int curr;
int arr[10];
int sol[10];
// here sol array and curr index making the stack
void gen(int i){
    if(i==n){
        for(int k=0;k<curr;k++){
            cout<<sol[k]<<" ";
        }
        cout<<endl;
        return ;
    }
    gen(i+1);
    sol[curr]=arr[i];
    curr++;
    gen(i+1);
    curr--;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    gen(0);

}
signed main(){
    solve();
}