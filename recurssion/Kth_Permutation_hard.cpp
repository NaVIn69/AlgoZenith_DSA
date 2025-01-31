#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void Kth_permutation(vector<int>&v,int k){
    // here we are finding the (n-1)! 
    // beacause in every iteration it divided my n(arr ka size) // beacause every iteration one digit is going to fixed
    int n=v.size();
    int fact=1;
    k--;
    for(int i=1;i<n;i++){
        fact=i*fact;
    }

    vector<int>ans;
    while(1){
        // first finding the first element of that permutation k/(n-1)! gives me the index of that element
         int index=k/fact;
         // we push that element in our array
         ans.push_back(v[index]);
         // erase that element from original array
         v.erase(v.begin()+index);
         if((int)v.size()==0) break;
         // finding the new k for the next element of size n-1
         k=k%fact;
         // here we are dividing the fact by size  for making (size-1)!
         fact=fact/(int)v.size();

    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
   
    if(n<=13){
        vector<int>v;
 
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
      
        Kth_permutation(v,k);

    }else{
        // 1 se n-11 tak koi effect nhi hoga
        // last ke n-12 se n tak wale element ka permutaion se find krenge kTh
        vector<int>v;
        for(int i=1;i<n-12;i++){
            cout<<i<<" ";
        }
        for(int i=n-12;i<=n;i++){
            v.push_back(i);
        }
        // here we are finding the last 13 element ka permutation
        Kth_permutation(v,k);
    }
    
    
}