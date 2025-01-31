#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct student{
    int s,e;
};
bool cmp(student&s1, student&s2){
    return s1.e<s2.e;
}
struct topK{
    int k;
    priority_queue<int>pq;
    int ksum=0;
    void init(int _k){
        k =_k;
        ksum=0;
    }
    void insert(int x){
        pq.push(-x);
        ksum+=x;
        if(pq.size()>k){
            //here we are removing the smallest value
            int sm=-pq.top();
            ksum-=sm;
        }
    }
    int getsum(){
        return ksum;
    }
};
void solve(){
    int n,k;
    cin>>n>>k;
    student arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].s>>arr[i].e;
    }
    sort(arr,arr+n,cmp);
    int ans=0;
    topK mytopk;
    mytopk.init(k-1);
    for(int i=n-1;i>=0;i--){
        if(n-i>=k){
           int strength=arr[i].s+mytopk.getsum();
           int effi=arr[i].e;
             ans=max(ans,strength*effi);

        }
        mytopk.insert(arr[i].s);

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