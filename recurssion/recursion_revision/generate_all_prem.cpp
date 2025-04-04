#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100];
vector<int>shared;
map<int,int>mpp;
void rec(int level){
   cout<<"level"<<" "<<level<<endl;
    if(level==n){
        // means we have taken all the element
        for(int i=0;i<shared.size();i++){
            cout<<shared[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    // here we explore all the element
    for(auto v:mpp){
        cout<<"trying choice on that level "<<v.second<<" "<<v.first<<endl;
        if(v.second!=0){
            cout<<"valid choice  "<<v.second<<" "<<v.first<<endl;
            // choice to take that element
            //place
            mpp[v.first]--;
            shared.push_back(v.first);
            rec(level+1);
            //unplace revert back
            mpp[v.first]++;
            shared.pop_back();
        }
    }
   
}

void solve(){
 cin>>n;
 for(int i=0;i<n;i++){
    cin>>arr[i];
    mpp[arr[i]]++;
 }
 rec(0);


}
signed main(){
    solve();
}