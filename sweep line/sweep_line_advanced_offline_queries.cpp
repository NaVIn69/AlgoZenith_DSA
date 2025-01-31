// we have given n interval and each interval some weight and we have to find the for queries
// given q queries  q=.{y,k}
//  n interval =>{l,r,x}
// y on that y we have to find the sum of topk elements


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using event=pair<pair<int,int>,pair<int,int>>;
#define F first
#define S second

/*
 0 ->start of that interval
 1 -> query on that interval
 2 -> end of that interval
 here both ends are inclusive
*/

/*
  both end exclussive
  l-2
  r-0
  y-1
*/

void solve(){
    int n,q;
    cin>>n;
    vector<event>events;
    for(int i=0;i<n;i++){
       int l,r,x;
       cin>>l>>r>>x;
       events.push_back({
        //start of interval
         {l,0},
         {x,i} 
       });
       events.push_back({
        //end of interval
        {r,2},
        { x,i}
       });
    }
    //queries
    cin>>q;
    for(int i=0;i<q;i++){
        //query
        int y,k;
        cin>>y>>k;
        events.push_back({
            {y,1},
            //here i represent the ith query
            {k,i}
        });
    }
    // we have inserted all the all events and all query
    sort(events.begin(),events.end());
    int ans1[q];
    multiset<int>mt;
    for(event v:events){
        if(v.F.S==0){
            // start the interval
            mt.insert(v.S.F);
        }else if(v.F.S==1){
            //query processing
            //we have to find the top ke k element ks sum
            int cnt=0;
            int ans=0;
            
            for(auto it=mt.rbegin();it!=mt.rend();it++){
                   ans+=*it;
                   cnt++;
                   if(cnt==v.S.F) break;
               
            }
            ans1[v.S.S]=ans;
        
    }else{
        // interval is endend;
        mt.erase(mt.find(v.S.F));
    }
}
for(int i=0;i<q;i++){
    cout<<ans1[i]<<endl;
}


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}