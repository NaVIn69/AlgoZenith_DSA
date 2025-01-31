// in Az workshop you have n problem which have given time and skill for every problem
// youe have x time and k slot to choose the problem to gain the maximum skill from that problem

// logic
/*
apply the LCCM
level = index of array which have given time and skill
choice =  dont take
           take 
 check
 move
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n;
int t[1001]; // here time is stored for every problem
int s[1001]; // skill -> from every problem how much skill i can get it
int taken[1001]; // it tells me about which problem  is taken or not 
int x,k;   // given x time and k slot of problem 

// find the maximum skill i can get it from  taking x time and k problem. 
  bool check(int level){
    int time_taken=0;
    int item_taken=0;
    for(int i=0;i<level;i++){
        if(taken[i]){
            time_taken+=t[i];
            item_taken++;
        }
    }
    time_taken+=t[level];
    item_taken++;
    if(time_taken<=x && item_taken<=k) return 1;
    else return 0;

  }
  int rec(int level){
    // maximum skill i can make from [level......n-1]
    //level ->current pos

    //base case
    if(level==n){
        // means we have been check all the element 
        return 0;
    }
  
   // choice
   //  choice 1::dont take
    
   int ans=rec(level+1);

   //choice2:: take
   if(check(level)){
    // here we check that can we take that problem or not( sum of time <=x && count of problem<=K)
    taken[level]=1;
    //move
    ans=max(ans,s[level]+rec(level+1));
   }
   // revert
   taken[level]=0;
   return ans; 

  }

void solve(){
    cin>>n>>x>>k;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    cout<<rec(0)<<endl;


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
