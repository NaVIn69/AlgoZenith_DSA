/*Given lengths of n ropes, we need to join them and make a single rope. Joining two ropes will make a single rope of length equal to the sum of both the ropes and also the cost of joining is also equal to the sum of ropes that are joined.

Example:

{4,4,3,2,6} => 43
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    int rope[n];
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        cin>>rope[i];
        pq.push(rope[i]);
    }
    if(n==1) cout<<rope[0]<<endl;
   int cost=0;
    while(!pq.empty()){
        int x=pq.top();
        pq.pop();
        if(pq.empty()){
            break;
        }
        int y=pq.top();
        pq.pop();
        cost+=(x+y);
        pq.push(x+y);

    }
    cout<<cost<<endl;


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