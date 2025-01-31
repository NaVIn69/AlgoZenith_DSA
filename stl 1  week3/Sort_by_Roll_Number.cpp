#include<bits/stdc++.h>
using namespace std;
#define int long long
struct student{
string name;
int roll;
};
bool cmp(const student&a,const student&b){
    return a.roll<b.roll;
}
void solve(){
    int n;
    cin>>n;
    student v[n];
    for(int i=0;i<n;i++){
       cin>>v[i].name;
       cin>>v[i].roll;
    }
    sort(v,v+n,cmp);
    for(int i=0;i<n;i++){
        cout<<v[i].name<<" "<<v[i].roll<<endl;
    }


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