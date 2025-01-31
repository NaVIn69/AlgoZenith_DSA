#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void Kth_move_tower_hanoi(int x,int source,int target,int aux,int k){
    if(x==0) return;
    if(k<=((1<<(x-1))-1)){
    Kth_move_tower_hanoi(x-1,source,aux,target,k);
    }
    else if(k==(1<<(x-1))){
    cout<<"MOve disc"<<x<<"from"<<source<<"to"<<target<<endl;
    }else{
    Kth_move_tower_hanoi(x-1,aux,target,source,k-(1<<(x-1)));
    }
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int x,k;
    cin>>x>>k;
    Kth_move_tower_hanoi( x,1,3,2,k);
}