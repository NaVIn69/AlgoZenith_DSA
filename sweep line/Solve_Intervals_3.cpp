#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using event =pair<pair<int,int>,pair<int,int>>;
#define F first
#define S second
void solve(){
    int n;
    cin>>n;
    vector<event>events;
    for(int i=0;i<n;i++){
        int l,r,x;
        cin>>l>>r>>x;
        events.push_back({
            {l,0},
            {x,i}
        });
        events.push_back({
            {r,2},
            {x,i}
        });
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int y,z;
        cin>>y>>z;
        events.push_back({
            {y,1},
            {z,i}  
        });
    }
    sort(events.begin(),events.end());
    int ans[q];
    multiset<int>mt;
    for(event v:events){
        if(v.F.S==0){
            //here interval has been started
            mt.insert(v.S.F);
        }else if(v.F.S==1){
          int Z=v.S.F;
         // for finding the value Z in multiset we can use the upper_bound
         auto it=mt.upper_bound(Z);
         if(it!=mt.begin()){
            it--;
            ans[v.S.S]=*it;
         }else{
            ans[v.S.S]=-1;
         }
        
        }else{
            mt.erase(mt.find(v.S.F));
        } 
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
 solve();
}