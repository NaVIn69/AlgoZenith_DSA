#include<bits/stdc++.h>
using namespace std;

struct monotone_deque_min{
    deque<int>dq;
    void insert(int x){
        while(!dq.empty()&&dq.back()>x){
            // here x is going to be minimum if it is greater than dq.back() element 
            dq.pop_back();
        }
        dq.push_back(x);

    }
    void Delete(int x){
        if(!dq.empty()&&dq.front()==x){
            dq.pop_front();
        }

    }
    int getminimum(){
        if(!dq.empty()) return dq.front();
    }
};
void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    monotone_deque_min mdq;
    // first phase
    for(int i=0;i<k;i++){
        mdq.insert(arr[i]);
    }
    cout<<mdq.getminimum()<<endl;
    /*
    for(int i=0;i<n-k;i++){
       mdq.insert(arr[i+k]);
       mdq.delete(arr[i]);
     }
    */
    // second phase
    for(int i=k;i<n;i++){
        mdq.insert(arr[i]);
        mdq.Delete(arr[i-k]);
        cout<<mdq.getminimum()<<endl;
    }
    cout<<endl;

}
signed main(){
    solve();
}