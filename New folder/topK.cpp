#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct topK{
    int k_;
    priority_queue<int>pq;
    int sum_K;
    void init(int k){
        k_=;
        sum_k=0;
    }
    void insert(int x){
        pq.insert(-x);
        sum_k+=x;
        if(pq.size()>k){
            int top=-pq.top();
            pq.pop();
            sum_k-=(top);
        }
    }
    int gettopK(){
        return sum_k;
    }
}
void solve(){

}
signed main(){
    solve();
}