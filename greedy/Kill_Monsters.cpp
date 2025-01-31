/*
There are N monsters in front of you. To defeat the i-th of them you need an army of Ai soldiers, Bi of which will be killed during the battle.
Now you want to know the minimal number of soldiers you need to recruit in order to kill all the monsters.
You don't care about the order of battles: the only thing that matters is that none of the monsters will be left alive.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool cmp(pair<int,int>&p1,pair<int,int>&p2){
   
   return (p1.first-p1.second)>(p2.first-p2.second);
   
}
void solve(){
    int n;
    cin>>n;
  pair<int,int> arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i].first>>arr[i].second;
  }
//   for(int i=0;i<n;i++){
//     cout<<arr[i].first<<" "<<arr[i].second<<endl;
//   }
  sort(arr,arr+n,cmp);
   for(int i=0;i<n;i++){
    cout<<arr[i].first<<" "<<arr[i].second<<endl;
  }
  int total=arr[0].first;
  int remaining=total-arr[0].second;
  int needed=0;
  for(int i=1;i<n;i++){
    int needed=arr[i].first-remaining;
    if(needed>0){
    total+=needed;
    if((remaining+needed)>=arr[i].first){
        remaining=remaining+needed-arr[i].second;
    }
    }else{
        remaining-=arr[i].second;
    }
  }
  cout<<total<<endl;

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