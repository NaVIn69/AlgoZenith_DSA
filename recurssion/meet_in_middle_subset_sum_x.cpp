// here   N<=40 here tc=O(2^n/2)
// for N<=20 we can do using bit msking or backtracking tc=o(2^n)
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// this generate function generate all the subset sum vector 
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
    int n,x;
    cin>>n>>x;
    vector<int>v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int>newarr[2];
    for(int i=0;i<n;i++){
        newarr[i&1].push_back(v[i]);
    }
    int ans=0;
    vector<int>sub0,sub1;
    sub0=generate(newarr[0]);
    sub1=generate(newarr[1]);
    // iterate on the sub0 ]
    // binary search on the sub1
    // sub1[i]<=x-sub0[i]; 
    for(auto v:sub0){
        ans+=upper_bound(sub1.begin(),sub1.end(),x-v)-sub1.begin();
    }
    cout<<ans<<endl;

}
signed main(){
    solve();
}