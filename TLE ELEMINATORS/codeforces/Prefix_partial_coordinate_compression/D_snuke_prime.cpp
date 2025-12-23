//1  a,b<=1e6 then we can use partial sum 
//2  a,b <=1e9 -> here we can use the sweep line and compressed compression to solve this 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,C;
int arr[200200];
int partial[200200];


// here using partial sum
// a,b<=1e6;
void solve(){
   cin>>n>>C;
   for(int i=0;i<n;i++){
     int l,r,c;
     cin>>l>>r>>c;
     partial[l]+=c;
     partial[r+1]-=c;
   }
   int tot=0;
   int ans=0;
   for(int i=1;i<=n;i++){
         partial[i]+=partial[i-1];
   }
   for(int i=0;i<=n;i++){
      ans+=min(C,partial[i]);
   }
   cout<<ans<<endl;

}

// here using sweep line 
// here in sweep line we directly move to the events 
void solve2(){
    cin>>n>>C;
    vector<pair<int,int>>events;
    for(int i=0;i<n;i++){
        int l,r,c;
        cin>>l>>r>>c;
        events.push_back({l,c});
        events.push_back({r+1,-c});
    }
    sort(events.begin(),events.end());
    int  total = 0;
int  curr_cost = 0; // it store the running cost of events 
    int prev_day = 0; 


    // here we calculate the cost of previous interval
    for(int i=0;i<events.size();i++){
        int day=events[i].first; // current day
        int cost=events[i].second; // cost of that event
        if(day!=prev_day){
            // here we are calculating the cost of previous interval
            total+=(day-prev_day)*(min(curr_cost,C));
            // for every interval we have to option 
            // using C buy each day 
            // using curr_cost 
            prev_day=day;
        }
        curr_cost+=cost;


    }
    cout<<total<<endl;
}
// using cordinate compression 
void solve3(){
    cin>>n>>C;
    vector<pair<pair<int,int>,int>>v;
    vector<int>temp;
    map<pair<int,int>,int>mpp;
    for(int i=0;i<n;i++){
        int l,r,c;
        cin>>l>>r>>c;
        v.push_back({{l,r},c});
        mpp[{l,r}]=c;
        temp.push_back(l);
        temp.push_back(r);
    }
    sort(temp.begin(),temp.end());
    



}
signed main(){
    solve2();
}