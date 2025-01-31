#include<bits/stdc++.h>
using namespace std;
void solve(){
    int t;  
    cin>>t;                                
long long  ans=0;
while(t--){
    int q,i;
   cin>>q;
   if(q<5){
    cin>>i;
   }

   switch(q){
 
 case 1: if(ans&(1<<i)){
    cout<<"1"<<endl;
 }else{
    cout<<"0"<<endl;
 }
 break;

 case 2: ans =ans |(1ULL<<i);
break;

case 3: ans=ans & (~(1ULL<<i));
break;

case 4: ans = ans ^(1ULL<<i);
break;

case 5: if(__builtin_popcount(ans)==60){
    cout<<"1"<<'\n';
}else{
    cout<<"0"<<'\n';
}
break;

case 6: if(__builtin_popcountll(ans)>=1){
    cout<<"1"<<endl;
}else{
    cout<<"0"<<endl;
}
break;

case 7:  if(ans==0){
    cout<<"1"<<'\n';
}else{
    cout<<"0"<<'\n';
}
break;


case 8: cout<<__builtin_popcountll(ans)<<'\n';
break;

case 9: cout<<ans<<'\n';
break;


   }
}

}
int main(){
    solve();
}