// here there are n question which have the proprety (score , decay(d), time)
// here score of question decay with rate d/sec
// we have to find  the maximum score after doing n question
 #include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct question
{ 
    int s,d,t;
    /* data */
};

 bool cmp(question&q1,question&q2){
    return 1LL*q1.t*q2.d< 1LL*q1.d*q2.t;
 }
void solve(){
    int n;
    cin>>n;
    question arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].s>>arr[i].d>>arr[i].t;
    }
    sort(arr,arr+n,cmp);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].s<<endl;
    // }
    int total_score=0;
    int time_spent=0;
    for(int i=0;i<n;i++){
        time_spent+=arr[i].t;
        total_score+=(arr[i].s-arr[i].d*time_spent);

    }
    cout<<total_score<<endl;


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