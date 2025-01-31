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
            if((mask>>i)&1){
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
vector<int>sub0,sub1;
sub0=generate(newarr[0]);
sub1=generate(newarr[1]);
set<int>st1(sub0.begin(),sub0.end());
set<int>st2(sub1.begin(),sub1.end());
vector<int>sub2(st1.begin(),st1.end());
vector<int>sub3(st2.begin(),st2.end());
for(int i=0;i<sub2.size();i++){
    cout<<sub2[i]<<" ";
}
cout<<endl;
for(int i=0;i<sub3.size();i++){
    cout<<sub3[i]<<" ";
}
cout<<endl;
int ans=0;
for(auto v:sub2){
   int index=upper_bound(sub3.begin(),sub3.end(),x-v)-sub3.begin();
  ans+=index;
}
cout<<ans<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
    solve();
    }
}