#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve(){
    int n;
    cin >> n;

    //missing during contest , atleast 2 size subarray has +ve sum, in -1,2,-1,2,-1 , doesnt satisfied {-1,2,-1}->0 
    if(n==2){
        cout<<"-1"<<" "<<"2"<<endl;
        //-1 3,-1,3,-1
    }else if(n%2==1){
         for(int i=0;i<n;i++){
            if(i%2==0){
                cout<<-1;
            }else{
                cout<<3;
            }
            if(i<n-1)cout<<" ";
         }
         cout<<endl;
        
    }else{
        for(int i=0;i<n-1;i++){
            if(i%2==0){
                cout<<-1;
            }else{
                cout<<3;
            }
            if(i<n-1)cout<<" ";
         }
         cout<<"2"<<" "<<endl;
         
         

    }
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}