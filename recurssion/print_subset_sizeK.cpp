#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,k;
int arr[100100];
vector<int>sol;
bool is_palindrome(vector<int>v){
    vector<int>v1;
    for(int i=0;i<v.size();i++){
        v1[i]=v[i];
    }
    reverse(v1.begin(),v1.end());
    return v1==v;
}
void rec(int level){
    if(level==n){
        // here we check that if my sol has size k means this is my possible vector
        // check
        if(sol.size()==k){
            if(is_palindrome(sol)){
            for(auto v:sol){
                cout<<v<<" ";
            }
            cout<<endl;
            }
            
          
         }
         return; 
    }
        
        //choice
          //take
          if(sol.size()<k){
          sol.push_back(arr[level]);
          //move
          rec(level+1);
          //revert 
          // means which has been we take just delete it and move to the next possible answer
          sol.pop_back();
          }
          
          // dont take
          rec(level+1);

    }


void solve(){
  
   cin>>n>>k;
   
   for(int i=0;i<n;i++) cin>>arr[i];
   // here level is the index of array 
   // we have to decide that we have to take index or not
   // we are starting with level means index 0 then we decide that we have to take that index or not
   rec(0);

}
signed main(){
    solve();
}