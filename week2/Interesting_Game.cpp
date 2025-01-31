#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool comp(pair<int,int>&a,pair<int,int>&b){
    return a.first+a.second>b.first+b.second;
}
void solve(){
    int n;
    cin>>n;
    int a[n],b[n];
    pair<int,int>p[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
          p[i].first=a[i];
        p[i].second=b[i];
    }
    sort(p,p+n,comp);
    int a_sum=0;
    int b_sum=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            a_sum+=p[i].first;
        }else{
            b_sum+=p[i].second;
        }
        cout<<a_sum<<" "<<b_sum<<endl;
    }
    if(a_sum>b_sum){
        cout<<"Alice"<<endl;
    }else if(a_sum==b_sum){
       cout<<"Tie"<<endl;
    }else{
        cout<<"Bob"<<endl;
    }


    

 
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}