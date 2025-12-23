#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

vector<int>solve(vector<int> &a, vector<int> &b, int c) {
    int n=a.size();
    // int m=b.size();
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<int>ans;
    // here we maintain the max heap with {sum ,{i,j}}
    // now we maintain the pair<int,int>p {i,j} into the set 
    priority_queue<pair<int,pair<int,int>>>pq;
    set<pair<int,int>>st;// here to check which {i,j} i have been inserted into the ans
    pq.push({a[n-1]+b[n-1],{n-1,n-1}});
    st.insert({n-1,n-1});
    // here we have to find the topk k sum combination , here we traversed k time and 
    for(int k=0;k<c;k++){
        pair<int,pair<int,int>>p=pq.top();
        pq.pop();
        int sum=p.first;
        int i=p.second.first;
        int j=p.second.second;
        ans.push_back(sum);
        // here we trying to inset the next element combonation
        if(i-1>=0){
            int new_sum=a[i-1]+b[j]; // 
            if(st.find({i-1,j})==st.end()){
                st.insert({i-1,j});
                pq.push({new_sum,{i-1,j}});
            }
            
        }
        if(j-1>=0){
            int new_sum=a[i]+b[j-1]; // 
            if(st.find({i,j-1})==st.end()){
                st.insert({i,j-1});
                pq.push({new_sum,{i,j-1}});
            }
        }
    }
  
    return ans;
    
    
    
}

signed main(){

}