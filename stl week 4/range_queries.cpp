#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we can do this problem with the help of partial sum but upto constarint 10^5 tak because isse badd size ka array nhi banna payenge
// but here we use another stl to solve if
void solve(){
// n section (interval)
int n,q;
cin>>n>>q;
vector<pair<int,int>>lvec;
vector<pair<int,int>>rvec;
while(n--){
    int l,r;
    // l and r are the interval on the number line
    cin>>l>>r;
    lvec.push_back({l,r});
    rvec.push_back({r,l});
}
sort(lvec.begin(),lvec.end());
sort(rvec.begin(),rvec.end());
while(q--){
    // here we have to give the answer at point that how many interval cut that line
    int x;
    cin>>x;
    // here we do reverse 
    // we calculate that how many intervals does not cut that line(x);
     // r<x ||l>x   that type of interval cant cut the 
     // for l
     int index_l=upper_bound(lvec.begin(),lvec.end(),x)-lvec.begin();
     int index_r=lower_bound(rvec.begin(),rvec.end(),x)-rvec.begin();
     cout<<(index_l-index_r)<<endl;


}


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){

    }
}