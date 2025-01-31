#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    vector<int>v={0,1,2,3,4,5,6,7,8,9};
    do{
        int abcde=v[0]*10000+v[1]*1000+v[2]*100+v[3]*10+v[4];
        int fghij=v[5]*10000+v[5]*1000+v[7]*100+v[8]*10+v[9];
        if(abcde%fghij==0){
            cout<<abcde<<" "<<fghij<<" "<<abcde/fghij<<endl;
        }
    }while(next_permutation(v.begin(),v.end()));


}
signed main(){
    solve();
}