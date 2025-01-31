#include<bits/stdc++.h>
using namespace std;
void solve(){
    vector<int>v({23, 23, 4, 3, 5, 3, 15, 15});
    int ans=0;
    for(int i=0;i<v.size();i++){
        ans=ans^v[i];
    }
  //  int set_bit=ans&(~(ans-1));
  int set_bit=ans&(-ans);/*

  for(int i=7;i>=0;i--){
    if(ans&(1<<i)){
      set_bit=(1<<i);
      break;
    }
  }*/
    vector<int>v1;
    vector<int> v2;
     int ans1=ans;
     int ans2=ans;
   for(int i=0;i<v.size();i++){
    if(set_bit&v[i]){
      ans1=ans1^v[i];
    }else{
      ans2=ans2^v[i];
    }
   }

  /*  for(int i=0;i<v1.size();i++){
        ans1=ans1^v1[i];
    }
 
    for(int i=0;i<v2.size();i++){
        ans2=ans2^v2[i];
    }*/
    cout<<ans1<<" "<<ans2<<endl;

}
int main(){
    solve();
}