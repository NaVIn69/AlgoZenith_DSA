#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int>generate(vector<int>v){
    vector<int>sub;
    int n=v.size();
    for(int mask=0;mask<(1<<n);mask++){
        int sum=0;
        for(int i=0;i<n;i++){
            if((v[i]>>mask)&1){
                sum+=v[i];
            }
        }
        sub.push_back(sum);
    }
    sort(sub.begin(),sub.end());
    return sub;
}
void solve(){
    int n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>ans=generate(v);

}
signed main(){
    solve();
}