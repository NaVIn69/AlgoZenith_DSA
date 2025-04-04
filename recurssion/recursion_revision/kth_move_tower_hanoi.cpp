#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k; // n discs

void kth_move(int discs,char source , char target, char aux,int k){
    // here first we have to place disc-1 discs from source to aux using target as the auxiliary
    // to place the disc-1 discs we need 2^(disc-1)-1 move atleast
    if(k<=((1<<(discs-1))-1)){
        kth_move(discs-1,source,aux,target,k);
    }else if(k==(1<<(discs-1))){
        cout<<"kth move from "<<source <<" to "<<target<<endl;
        return;
    }else{
        kth_move(discs-1,aux,target,source,k-(1<<(discs-1)));
    }


}
void solve(){
  cin>>n;
  for(int i=1;i<=7;i++){
  kth_move(n,'A','C','B',i);
  }

}
signed main(){
    solve();
}