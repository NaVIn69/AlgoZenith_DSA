// here we have to find the 4 distnict element
// here we have to find the 4 distnict element which sum is equal to target
// here we use the partition 
// in map we keep the sum of (c+d)
// and we iterate for (a+b)

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,target;
int arr[10010];
vector<int> is_4sum(){
    map<int,pair<int,int>>pos;
    for(int b=n-2;b>=1;b--){
         for(int a=b-1;a>=0;a--){
              if(pos.find(target-arr[a]-arr[b])!=pos.end()){
                     pair<int,int>p=pos[target-arr[a]-arr[b]];
                     return {a,b,p.first,p.second};
              }
         }
         int c=b;
         for(int d=c+1;d<n;d++){
            pos[arr[c]+arr[d]]={c,d};
         }
    }
  

}
void solve(){
cin>>n>>target;
for(int i=0;i<n;i++) cin>>arr[i];
vector<int>ans=is_4sum();
for(int i=0;i<ans.size();i++){
    cout<<arr[ans[i]]<<" ";
}
cout<<endl;
// if(is_4sum()){
//     cout<<"YES"<<endl;
// }else{
//     cout<<"NO"<<endl;
// }

}
signed main(){
   solve();
}