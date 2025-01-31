// here we have to find that arr[a]+arr[b]+arr[c]+arr[d]==target a,b,c,d may be same;
// first we store the a+b in the map 
// then check for c+d
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int a[10010];
bool is_4sum(){
    map<int,int>pos;
    // here map store the a+b sum;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            pos[a[i]+a[j]]=1;
        }
    }
    // check for the c+d
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(pos[a[i]+a[j]]){
                return 1;
            }
        }
    }
    return 0;
}
void solve(){

    cin>>n;

    for(int i=0;i<n;i++) cin>>a[i];
    bool ans=is_4sum();
    cout<<ans<<endl;
    

}
signed main(){
    solve();
}
 