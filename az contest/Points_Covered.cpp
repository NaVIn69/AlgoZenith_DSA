#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve(){
vector<vector<int>>intervals;
int n;
cin>>n;
while(n--){
    int a,b;
    cin>>a>>b;
    vector<int>v1;
    v1.push_back(a);
    v1.push_back(b);
    intervals.push_back(v1); 
}
//sort(intervals.begin(),intervals.end());
 int size=intervals.size();
        if(size==1){
           int a=intervals[0][0];
           int b=intervals[0][1];
           if(a*b<0){
            cout<<abs(b-a)+2<<endl;
            return;
           }else{
            cout<<abs(b-a)+1<<endl;
            return ;
           }
            
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int f=intervals[0][0];
        int s=intervals[0][1];
        for(int i=0;i<size-1;i++){

            vector<int>v;
             if(s>=intervals[i+1][0]){
                 s=max(s,intervals[i+1][1]);
             }else{
                   v.push_back(f);
                   v.push_back(s);
                   ans.push_back(v);
                   f=intervals[i+1][0];
                   s=intervals[i+1][1];

             }
        }
        vector<int>v4;
        v4.push_back(f);
        v4.push_back(s);
        ans.push_back(v4);
        int cnt=0;
        for(int i=0;i<ans.size();i++){

             int a=ans[i][0];
           int b=ans[i][1];
          // cout<<a<<" "<<b<<endl;
          cnt+=(abs(b-a)+1);
        }
        cout<<cnt<<endl;


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