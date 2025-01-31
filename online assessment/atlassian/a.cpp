#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){ 
    int n;
    cin>>n;
    int arr[n],brr[n];
    map<int,int>mppa,mppb;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mppa[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        cin>>brr[i];
        mppb[brr[i]]++;
    }
     map<int,vector<int>>mppc;
     for(auto v:mppa){
        int cntb=mppb[v.first];
        mppc[abs(cntb-v.second)].push_back(v.first);
     }
     for(auto v:mppb){
        int cnta=mppa[v.first];
        mppc[abs(cnta-v.second)].push_back(v.first);
     }
     int cost=0;

     for(auto v:mppc){
        cout<<v.first<<" "<<endl;;
        
        vector<int>x=v.second;
        cout<<"array"<<" "<<endl;
         for(int i=0;i<x.size();i++){
                cout<<x[i]<<" ";
             }
             

        // if(x.size()%2){
        //     cout<<"-1"<<endl;
        //     return ;
        // }else{
        //     sort(x.begin(),x.end());
        //     for(int i=0;i<x.size();i+=2){
        //         cost+=x[i];
        //     }
        // }
        
     }
     cout<<cost<<endl;

}
signed main(){
    solve();
}