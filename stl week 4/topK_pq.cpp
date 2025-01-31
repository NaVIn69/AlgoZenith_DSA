#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int k;
struct bag{
    int sumk=0;
   // here we can directly take min heap 
    priority_queue<int,int>pq;
    // here we take max heap then we convert into the min heap by multiplying with -1
    void insert(int x){
        pq.push(-x);
        sumk+=x;
        if(pq.size()>k){
            int sm=-(pq.top());
            sumk-=x;
            pq.pop();
        }
    }
    int topK(){
        return sumk;
    }


};
signed main(){
    cin>>k;
    bag b1;
    b1.insert(9);
    b1.insert(7);
    b1.insert(10);
}