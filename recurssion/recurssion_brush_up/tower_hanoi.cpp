#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void tower_hanoi(int x,char sources,char aux,char target){
     if(x==0) return;

    // first we transfer the (x-1) disc from sources to aux using the target as aux
    tower_hanoi(x-1,sources,target,aux);
    cout<<" Move disc "<<x<<" from "<<sources<<" to "<<target<<" using "<<aux<<endl;
    tower_hanoi(x-1,aux,sources,target);

}

void solve(){
    int n;
    cin>>n;
    tower_hanoi(n,'A','B','C');

}
signed main(){
    solve();
}