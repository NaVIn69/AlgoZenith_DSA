#include<bits/stdc++.h>
using namespace std;
int sum=0;
map<int,int>mpp;
int cnt=0;
void insert(int x){
    cnt++;
    sum+=x;
    mpp[x]++;
}
int get_sum(){
    return sum;
}
int get_max(){
    auto it=mpp.rbegin();
    return it->first;
    // (*mpp.rbegin()).first;
}
int distinct_ele(){
    return mpp.size();
}
int total_ele(){
    return cnt;
}
void remove_ele(int x){
    mpp[x]--;
    cnt--;
    sum-=x;
    if(mpp[x]==0) mpp.erase(x);


}
int present(int x){
    if(mpp.find(x)!=mpp.end()){
         return 1;
    }
    return 0;
}
int greater_than(int k){
    auto it=mpp.upper_bound(k);
    return it->first;
}
void solve(){

insert(2);
insert(5);
insert(8);
cout<<get_sum()<<'\n';
cout<<total_ele()<<'\n';
for(auto x:mpp){
    cout<<x.first<<"->"<<x.second<<'\n';
}
remove_ele(5);
cout<<total_ele()<<'\n';
cout<<greater_than(5)<<'\n';

}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}