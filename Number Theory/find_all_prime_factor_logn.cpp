#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
// here sp[i] store the smallest prime factor of i
int sp[1000100];

void smallestPrimefact(int n){
    for(int i=2;i<=n;i++){
        sp[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(sp[i]==i){
            // then we put all the multiples of i as smallest prime factor as i 
            for(int j=2*i;j<=n;j+=i){
              if(sp[j]==j){
                sp[j]=i;
              }
            }
        }
    }
    // here we have been fill the smallest prime factor in sp array
}
vector<int>primefact(int x){
    vector<int>ans;
    while(x>1){
        ans.push_back(sp[x]);
        x=x/sp[x];
    }
    return ans;

}


void solve(){
    int n;
    cin>>n;
    // here we have to find all the prime number from 1 to n;
    smallestPrimefact(n);
    int q;
    while(q--){
        int x;
        cin>>x;
        vector<int>fact=primefact(x);
        map<int,int>mpp;
        for(auto y:fact){
            mpp[y]++;
        }
        cout<<endl;

    }

}
signed main(){
    solve();
}