#include<bits/stdc++.h>
using namespace std;
#define int long long
 void solve(){
     int q;
     cin>>q;
     int ans=0;
     while(q--){
      int ch;
      cin>>ch;
 
      if(ch==1){
        int i;
        cin>>i;
        if((ans>>i)&1LL){
            cout<<"1"<<endl;
        }else{
            cout<<"0"<<endl;
        }
      }else if(ch==2){
         int i;
         cin>>i;
         ans=(ans|(1LL<<i));
        //  cout<<"ans 2"<<" "<<ans<<endl;
      }else if(ch==3){
        int i;
        cin>>i;
        ans=(ans&(~(1LL<<i)));

      }else if(ch==4){
        int i;
        cin>>i;
        ans=ans^(1LL<<i);

      }else if(ch==5){
        if(__builtin_popcountll(ans)==60){
            cout<<"1"<<endl;
        }else{
            cout<<"0"<<endl;
        }

      }else if(ch==6){
        if(__builtin_popcountll(ans)>=1){
            cout<<"1"<<endl;
        }else{
            cout<<"0"<<endl;
        }
      }else if(ch==7){
          if(ans==0){
            cout<<"1"<<endl;
        }else{
            cout<<"0"<<endl;
        }
      }else if(ch==8){
      cout<<__builtin_popcountll(ans)<<endl;

      }else if(ch==9){
         cout<<ans<<endl;
      }
     }
 }
 signed main(){
    int t=1;
    while(t--){
        solve();
    }
 }