#include<bits/stdc++.h>
using namespace std;
vector<long long>solve(int N,int Q,vector<int>A,vector<vector<int>>query){
      vector<long long>ans1;
      for(int i=0;i<query.size();i++){
           int op=query[i][0];
           if(op==1){
            A[query[i][1]-1]=query[i][2];
           }else{
            int l=query[i][1];
            int r=query[i][2];
            int len=(r-l+1);
            int ans=0;
            for(int i=l;i<=r;i++){
                 ans+=((len-i)*(i+1)*A[i]);
            }
            ans1.push_back(ans);
           }
      }
      return ans1;
}
int  main(){
    return 0;
}